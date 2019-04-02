/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:14:49 by thaley            #+#    #+#             */
/*   Updated: 2019/03/30 15:39:31 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		write_info(char *direct, t_flags *flag)
{
	t_ls			*ls;
	DIR				*dir;

	ls = NULL;
	dir  = NULL;
	if ((dir = opendir(direct)) == NULL) //TODO: normal error
	{
		ft_putstr("ft_ls: ");
		ft_putstr(direct);
		ft_putstr(": No such file or directory\n");
		exit(1);
	}
	ls = add_list(ls);
	write_name(ls, dir);
	closedir(dir);
	sort_string(ls, flag);
	print_ls(ls, flag);
	return (0);
}

int		write_name(t_ls *ls, DIR *dir)
{
	struct dirent	*file;
	t_ls			*head;

	file = NULL;
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
	return (0);
}
