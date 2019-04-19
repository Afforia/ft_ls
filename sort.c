/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 05:05:33 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 05:30:01 by thaley           ###   ########.fr       */
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
