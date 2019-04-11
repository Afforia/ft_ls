/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:32:53 by thaley            #+#    #+#             */
/*   Updated: 2019/04/11 22:40:45 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag	*crt_flag()
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
	}
	return (flag);
}

t_dir	*crt_dir(t_dir *head)
{
	t_dir	*new;
	t_dir	*tmp;

	tmp = head;
	new = malloc(sizeof(t_dir));
	new->count = 0;
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

t_ls	*add_ls(t_ls *head)
{
	t_ls	*tmp;
	t_ls	*new;

	tmp = head;
	new = malloc(sizeof(t_ls));
	new->next = NULL;
	new->sort = NULL;
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
