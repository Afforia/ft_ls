/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:11:00 by thaley            #+#    #+#             */
/*   Updated: 2019/03/27 18:50:24 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* return 1 if smth wrong. 0 = all OK */
/* here must done all with 1 dir and ONLY then go to next */

int		get_name(DIR *dir, char *direct, t_flags *flag)
{
	t_ls			*ls;
	t_ls			*head;
	struct dirent	*file;
	
	ls = NULL;
	head = NULL;
	file = NULL;
	if ((dir = opendir(direct)) == NULL)
		return (1);
	ls = add_list(ls);
	head = ls;
	while ((file = readdir(dir)) != NULL)
	{
		if (ls->name)
		{
			ls->next = add_list(ls);
			ls = ls->next;
		}
		ls->name = ft_strdup(file->d_name);
	}
	ls = head;
	closedir(dir);
	dir = NULL;
	string_sort(ls);
	options(ls, flag);
	return (0);
}

/*
** mb dont corecte with last element!
*/

int		string_sort(t_ls *ls)
{
	t_ls	*head;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (ls == NULL)
		return (1);
	head = ls;
	while (ls)
	{
		if (ls->next == NULL)
		{
			if (string_sort(head->next))
				return (1);
		}
		i = ft_strcmp(ls->name, head->name);
		if (i < 0)
		{
			tmp = head->name;
			head->name = ls->name;
			ls->name = tmp;
		}
		ls = ls->next;
	}
	return (0);
}

int		options(t_ls *ls, t_flags *flag)
{
	int		blocks;

	blocks = 0;
	if (flag->l)
	{
		blocks = get_info(ls);
		user_info(ls);
		acess(ls);
	}
	printf("total: %d\n", blocks);
	while (ls)
	{
		printf("%d ", ls->link);
		printf("%-1s ", ls->user_name);
		printf("%-1s ", ls->group_name);
		printf("%5d ", ls->size);
		printf("%-1s ", ls->m_time);
		printf("%1s\n", ls->name);
		ls = ls->next;
	}
	return (0);
}

int		get_info(t_ls *ls)
{
	struct stat	buf;
	int			blocks;

	blocks = 0;
	while (ls)
	{
		stat(ls->name, &buf);
		ls->m_time = ft_strsub(ctime(&buf.st_mtime), 4, 12); //только нужная часть даты
		ls->link = buf.st_nlink;
		ls->size = buf.st_size;
		ls->uid = buf.st_uid;
		ls->acess = ft_unitoa(buf.st_mode);
		ls->block = buf.st_blocks; //лучше сделать все таки чаровским
		blocks = blocks + ls->block;
		printf("%s\n", ls->acess);
		ls = ls->next;
	}
	return (blocks);
}

void	user_info(t_ls *ls)
{
	struct passwd	*userinfo;
	struct group	*grinfo;

	userinfo = getpwuid(ls->uid);
	grinfo = getgrgid(userinfo->pw_gid);
	while (ls)
	{
		ls->user_name = ft_strdup(userinfo->pw_name);
		ls->group_name = ft_strdup(grinfo->gr_name);
		ls = ls->next;
	}
}

void	acess(t_ls *ls)
{
	t_ls		*head;
	t_access	*new;

	new = creat_access(ls, new);
	head = new;
	while (ls)
	{
		if (new->type)
		{
			new->next = add_list(new);
			new = new->next;
		}
		if (ls->acess[0] == '1')
			new->type = ft_strdup("-");
		else
			new->type = ft_strdup("d");
		new->user = take_chmod(ls->acess);
		new->group = take_chmod(ls->acess);
		new->other = take_chmod(ls->acess);
		new = new->next;
		ls = ls->next;
	}
}
