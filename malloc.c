/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:52:12 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 05:36:57 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag		*crt_flag(void)
{
	t_flag	*new;

	if (!(new = malloc(sizeof(t_flag))))
	{
		perror("don't allocate memory\n");
		return (NULL);
	}
	new->d_count = 0;
	new->R = 0;
	return (new);
}

t_dir		*crt_dir(t_dir *head)
{
	t_dir	*new;
	t_dir	*tmp;

	tmp = head;
	new = malloc(sizeof(t_dir));
	new->next = NULL;
	new->drct = NULL;
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

t_file		*crt_file(t_file *head)
{
	t_file		*new;
	t_file		*tmp;

	tmp = head;
	new = malloc(sizeof(t_file));
	new->next = NULL;
	new->d_name = NULL;
	new->name = NULL;
	new->type = 0;
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
