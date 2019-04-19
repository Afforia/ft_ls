/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 05:05:33 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 06:44:47 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			sort_dir(t_dir *drct)
{
	t_dir	*head;
	char	*tmp;

	tmp = NULL;
	if (drct == NULL)
		return (1);
	head = drct;
	while (drct)
	{
		if ((ft_strcmp(drct->drct, head->drct)) < 0)
		{
			tmp = head->drct;
			head->drct = drct->drct;
			drct->drct = tmp;
		}
		drct = drct->next;
		if (drct == NULL)
		{
			if ((sort_dir(head->next)))
				return (1);
		}
	}
	return (0);
}

/*
** sort_names -> 28 lines!!!
*/

int			sort_names(t_file *names)
{
	t_file			*head;
	t_file			*tmp;
	unsigned int	t;

	t = 0;
	tmp = NULL;
	if (names == NULL)
		return (1);
	head = names;
	while (names)
	{
		if (((ft_strcmp(names->name, head->name)) < 0)
		&& (ft_strcmp(names->d_name, head->d_name) == 0))
		{
			change(&names->d_name, &head->d_name);
			change(&names->name, &head->name);
			t = head->type;
			head->type = names->type;
			names->type = t;
		}
		names = names->next;
		if (names == NULL)
		{
			if (sort_names(head->next))
				return (1);
		}
	}
	return (0);
}

void		change(char **str, char **str2)
{
	char	*tmp;

	tmp = *str2;
	*str2 = *str;
	*str = tmp;
}
