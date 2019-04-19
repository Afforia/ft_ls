/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:32:53 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 03:08:30 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag		*crt_flag(void)
{
	t_flag	*flag;

	flag = NULL;
	{
		if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
			return (NULL);
		flag->l = 0;
		flag->a = 0;
		flag->r = 0;
		flag->R = 0;
		flag->t = 0;
		flag->dir_count = 0;
	}
	return (flag);
}

t_dir		*crt_dir(t_dir *head)
{
	t_dir	*new;
	t_dir	*tmp;

	tmp = head;
	new = malloc(sizeof(t_dir));
	new->dirent = NULL;
	new->next = NULL;
	if (tmp == NULL)
	{
		head = new;
		return (new);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_ls		*crt_ls(t_ls *head)
{
	t_ls	*tmp;
	t_ls	*new;

	tmp = head;
	new = malloc(sizeof(t_ls));
	new->next = NULL;
	new->sort = crt_sort();
	new->chmod = NULL;
	if (tmp == NULL)
	{
		head = new;
		return (new);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_sort		*crt_sort(void)
{
	t_sort	*new;

	new = malloc(sizeof(t_sort));
	new->mnth = 0;
	new->print_name = NULL;
	new->sec = 0;
	new->type = 0;
	new->week = 0;
	new->year = 0;
	new->day = 0;
	new->hour = 0;
	new->min = 0;
	new->m_time = NULL;
	return (new);
}

t_output	*crt_out(t_output *head)
{
	t_output	*tmp;
	t_output	*new;

	tmp = head;
	new = malloc(sizeof(t_output));
	new->next = NULL;
	new->dir_name = NULL;
	new->print = NULL;
	if (tmp == NULL)
	{
		head = new;
		return (new);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
