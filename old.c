/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:09:55 by thaley            #+#    #+#             */
/*   Updated: 2019/03/26 16:27:09 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//7890
int		main(int argc, char **argv)
{
	DIR		*dir;
	t_ls	*info;
	int		blocks;

	blocks = 0;
	info = NULL;
	if (argc == 1)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);
	if (dir == NULL)
	{
		write(1, "error\n", 7);
		exit (1);
	}
	info = some_func(dir);
	blocks = write_info(info); //acess rights, size of files in block, time, hard links
	user_info(info); //info about group and user
	string_sort(info);
	while (info)
	{
		printf("%s\n", info->name);
		info = info->next;
	}
	// print_all(info);
	// free_list(&info, del_ls);
	// free(info);
	return (0);
}

/* correct */

t_ls	*some_func(DIR *dir)
{
	t_ls			*new;
	t_ls			*head;
	struct dirent	*file;
	int				i;
	int				count;

	i = 0;
	count = 0;
	new = NULL;
	new = add_list(new);
	head = new;
	while ((file = readdir(dir)) != NULL)
	{
		if (new->name)
		{
			new->next = add_list(new);
			new = new->next;
		}
		new->name = (char *)malloc(sizeof(char) * file->d_namlen);
		new->name = ft_strcpy(new->name, file->d_name);
		count++;
		new->count = count;
	}
	new = head;
	return (new);
}

/* correct */

t_ls	*add_list(t_ls *head)
{
	t_ls	*tmp;
	t_ls	*new;

	tmp = head;
	new = (t_ls *)malloc(sizeof(t_ls));
	new->count = 0;
	new->size = 0;
	new->link = 0;
	new->uid = 0;
	new->name = NULL;
	new->acess = NULL;
	new->m_time = NULL;
	new->user_name = NULL;
	new->group_name = NULL;
	new->next = NULL;
	if (tmp == NULL)
		head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

/* not work */

void	free_list(t_ls **head, void del_ls(t_ls *))
{
	t_ls	*tmp;
	if (!(*head))
		return ;
	tmp = (*head);
	while ((*head)->next)
		free_list(&(*head)->next, del_ls);
	free((*head)->name);
	(*head)->name = NULL;
}

void	del_ls(t_ls *tmp)
{
	free(tmp);
}

int		write_info(t_ls *info)
{
	struct stat	buf;
	int			blocks;

	blocks = 0;
	while (info)
	{
		stat(info->name, &buf);
		info->m_time = ft_strsub(ctime(&buf.st_mtime), 4, 12); //только нужная часть даты
		info->link = buf.st_nlink;
		info->size = buf.st_size;
		info->uid = buf.st_uid;
		info->acess = ft_unitoa(buf.st_mode);
		info->block = buf.st_blocks; //лучше сделать все таки чаровским
		blocks = blocks + info->block;
		info = info->next;
	}
	return (blocks);
}

/* понять как выравнивать таблицы */

void	print_all(t_ls *info)
{
	while (info)
	{
		ft_putnbr(info->link);
		ft_putstr("  ");
		ft_putstr(info->user_name);
		ft_putstr("  ");
		ft_putstr(info->group_name);
		ft_putstr("  ");
		ft_putnbr(info->size);
		ft_putstr("  ");
		ft_putstr(info->m_time);
		ft_putstr("  ");
		ft_putstr(info->name);
		ft_putstr("\n");
		info = info->next;
	}
}

void	user_info(t_ls *info)
{
	struct passwd	*userinfo;
	struct group	*grinfo;

	userinfo = getpwuid(info->uid);
	grinfo = getgrgid(userinfo->pw_gid);
	while (info)
	{
		info->user_name = ft_strdup(userinfo->pw_name);
		info->group_name = ft_strdup(grinfo->gr_name);
		info = info->next;
	}
}

/*
** work correct!
*/

int		string_sort(t_ls *info)
{
	t_ls	*head;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (info == NULL)
		return (1);
	head = info;
	while (info)
	{
		if (info->next == NULL)
		{
			if (string_sort(head->next))
				return (1);
		}
		i = ft_strcmp(info->name, head->name);
		if (i < 0)
		{
			tmp = head->name;
			head->name = info->name;
			info->name = tmp;
		}
		info = info->next;
	}
	return (0);
}
