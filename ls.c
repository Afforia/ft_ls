/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 02:02:09 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 03:23:25 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*take_name(DIR *dir, t_dir *direct, t_flag *flag)
{
	struct dirent	*file;
	t_ls			*new;
	t_ls			*head;

	new = crt_ls(NULL);
	head = new;
	direct->len = ft_strlen(direct->direct);
	while ((file = readdir(dir)))
	{
		if (!flag->a && file->d_name[0] == '.')
			continue;
		if (new->sort->print_name)
		{
			new->next = crt_ls(new);
			new = new->next;
		}
		new->sort->print_name = ft_strdup(file->d_name);
		new->sort->type = file->d_type;
	}
	return (head);
}

void	output(t_ls *ls, t_flag *flag, char *direct, t_output *print)
{
	int		count;

	count = 0;
	if (flag->dir_count > 1)
		print->dir_name = ft_strdup(direct);
	if (flag->t)
		time_sort(ls, flag->r);
	if (flag->l)
		count = take_info(ls);
	if (flag->R)
		check_dir(ls);
}
