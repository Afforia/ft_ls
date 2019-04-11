/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:17:59 by thaley            #+#    #+#             */
/*   Updated: 2019/04/11 22:56:38 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_flag	*flag;
	t_dir	*dir;
	t_dir	*head;
	int		i;
	int		tmp;

	tmp = 0;
	dir = NULL;
	head = NULL;
	i = 1;
	flag = crt_flag();
	if (argv[i] && i == 1)
	{
		while (argv[i] && argv[i][0] == '-')
		{
			if (find_flag(flag, argv[i]))
			{
				printf("ft_ls: illegl option -- %s\nusage: ft_ls [-Ralrt] [file ...]\n", argv[i]);
				return (-1);
			}
			i++;
		}
	}
	if (i == 1)
	{
		while (argv[i])
		{
			dir = take_dir(argv[i], dir);
			if (dir->count == 1)
				head = dir;
			i++;
		}
	}
	else
	{
		tmp = i;
		while (argv[i])
			i++;
		while (i > tmp)
		{
			--i;
			dir = take_dir(argv[i], dir);
			if (dir->count == 1)
				head = dir;
		}
	}
	if (argc == 1 || !dir)
		dir = take_dir(".", dir);
	else
		dir = head;
	info(dir, flag);
	return (0);
}

int			find_flag(t_flag *flag, char *argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		argv[i] == 'l' ? (flag->l = 1) : j++;
		argv[i] == 'a' ? (flag->a = 1) : j++;
		argv[i] == 'r' ? (flag->r = 1) : j++;
		argv[i] == 'R' ? (flag->R = 1) : j++;
		argv[i] == 't' ? (flag->t = 1) : j++;
		if (j == 5)
			return (1);
		i++;
	}
	return (0);
}

t_dir		*take_dir(char *direct, t_dir *dir)
{
	static int		count;
	char			*tmp;

	tmp = ft_strnew(ft_strlen(direct) + 1);
	tmp = ft_strcpy(tmp, direct);
	tmp = ft_strcat(tmp, "/");
	if (dir == NULL)
	{
		count = 1;
		dir = crt_dir(NULL);
	}
	else
	{
		while (dir->next != NULL)
			dir = dir->next;
		dir->next = crt_dir(dir);
		dir = dir->next;
	}
	dir->dirent = ft_strdup(tmp);
	dir->count = count;
	count++;
	free(tmp);
	tmp = NULL;
	return (dir);
}

void		info(t_dir *dir, t_flag *flag)
{
	t_ls	*ls;

	ls = take_name(dir, flag->a);
	while (ls)
	{
		printf("%s\n", ls->sort->dir_name);
		ls = ls->next;
	}
}

t_ls		*take_name(t_dir *direct, int flag)
{
	t_ls			*new;
	DIR				*dir;

	new = NULL;
	while (direct)
	{
		if ((dir = opendir(direct->dirent)) == NULL)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(direct->dirent);
			ft_putstr(": No such file or directory\n");
			exit(1);
		}
		new = write_path(dir, direct, flag);
		direct = direct->next;
		closedir(dir);
	}
	return (new);
}

t_ls		*write_path(DIR *dir, t_dir *direct, int flag)
{
	struct dirent	*file;
	t_ls			*new;
	t_ls			*head;

	direct->len = ft_strlen(direct->dirent);
	new = add_ls(NULL);
	head = new;
	while ((file = readdir(dir)))
	{
		if (new->sort)
		{
			new->next = add_ls(new);
			new = new->next;
		}
		if (flag && file->d_name[0] == '.')
			continue;
		new->sort = malloc(sizeof(t_sort));
		new->sort->dir_name = ft_strnew(direct->len + file->d_namlen + 1);
		new->sort->dir_name = ft_strcpy(new->sort->dir_name, direct->dirent);
		new->sort->dir_name = ft_strcat(new->sort->dir_name, file->d_name);
		new->sort->print_name = ft_strdup(file->d_name);
	}
	new = head;
	return (new);
}
