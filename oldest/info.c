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
		i = ft_strcmp(ls->name, head->name);
		if (i < 0)
		{
			tmp = head->name;
			head->name = ls->name;
			ls->name = tmp;
		}
		ls = ls->next;
		if (ls == NULL)
		{
			if (string_sort(head->next))
				return (1);
		}
	}
	return (0);
}

int		options(t_ls *ls, t_flags *flag)
{
	t_access	*access;
	int			blocks;

	blocks = 0;
	access = NULL;
	if (flag->a == 0)
		ls = delete_hiden(ls);
	if (flag->r == 1)
		re_sort(ls);
	if (flag->l)
	{
		blocks = get_info(ls); 
		user_info(ls);
		access = acess(ls);
	}
	print_ls(ls, flag, access, blocks);
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

t_access	*acess(t_ls *ls)
{
	t_access	*head;
	t_access	*new;

	new = NULL;
	new = creat_access(new);
	head = new;
	while (ls)
	{
		if (new->type)
		{
			new->next = creat_access(new);
			new = new->next;
		}
		if (ls->acess[0] == '1')
			new->type = ft_strdup("-");
		else
			new->type = ft_strdup("d");
		new->user = take_chmod(ls->acess, 1);
		new->group = take_chmod(ls->acess, 2);
		new->other = take_chmod(ls->acess, 3);
		ls = ls->next;
	}
	new = head;
	return (new);
}

char	*take_chmod(char *access, int num)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (access[i])
		i++;
	if (num == 1)
		i = i - 3;
	else if (num == 2)
		i = i - 2;
	else
		i = i - 1;
	access[i] == '0' ? new = ft_strdup("---") : 0;
	access[i] == '1' ? new = ft_strdup("--x") : 0;
	access[i] == '2' ? new = ft_strdup("-w-") : 0;
	access[i] == '3' ? new = ft_strdup("-wx") : 0;
	access[i] == '4' ? new = ft_strdup("r--") : 0;
	access[i] == '5' ? new = ft_strdup("r-x") : 0;
	access[i] == '6' ? new = ft_strdup("rw-") : 0;
	access[i] == '7' ? new = ft_strdup("rwx") : 0;
	return (new);
}

t_ls	*delete_hiden(t_ls *ls)
{
	t_ls	*head;

	head = NULL;
	while (ls->name[0] == '.')
	{
		head = ls->next;
		free(ls);
		ls = head;
	}
	return (ls);
}

int		re_sort(t_ls *ls)
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
		i = ft_strcmp(ls->name, head->name);
		if (i > 0)
		{
			tmp = head->name;
			head->name = ls->name;
			ls->name = tmp;
		}
		ls = ls->next;
		if (ls == NULL)
		{
			if (re_sort(head->next))
				return (1);
		}
	}
	return (0);
}