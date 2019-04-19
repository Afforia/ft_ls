/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:59:52 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 03:09:07 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*take_dir(char **argv, t_flag **flag)
{
	t_dir	*new;
	t_dir	*head;
	int		i;

	new = crt_dir(NULL);
	head = new;
	i = 1;
	*flag = find_flag(argv, &i);
	if (argv[i])
	{
		while (argv[i])
		{
			new = wr_dir(argv[i], new);
			(*flag)->dir_count++;
			i++;
		}
	}
	else
	{
		(*flag)->dir_count = 1;
		new->direct = ft_strdup(".");
		new->len = 2;
	}
	return (head);
}

t_dir		*wr_dir(char *argv, t_dir *dir)
{
	if (dir->direct != NULL)
	{
		while (dir->next != NULL)
			dir = dir->next;
		dir->next = crt_dir(dir);
		dir = dir->next;
	}
	dir->direct = ft_strnew(ft_strlen(argv) + 1);
	dir->direct = ft_strcpy(dir->direct, argv);
	dir->direct = ft_strcat(dir->direct, "/");
	dir->len = ft_strlen(dir->direct);
	return (dir);
}

void		dir_content(t_dir *direct, t_flag *flag)
{
	DIR			*dir;
	t_ls		*ls;
	t_output	*print;
	t_output	*head;

	dir = NULL;
	ls = NULL;
	sort_dir(direct, flag->r);
	print = crt_out(NULL);
	head = print;
	while (direct)
	{
		if ((dir = opendir(direct->direct)) == NULL)
		{
			printf("ft_ls: %s: no such file or directory.\n", direct->direct);
			direct = direct->next;
			continue;
		}
		ls = take_name(dir, direct, flag);
		output(ls, flag, direct->direct, print);
		direct = direct->next;
		print = print->next;
		closedir(dir);
	}
}
