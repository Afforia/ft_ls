/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:28:07 by thaley            #+#    #+#             */
/*   Updated: 2019/06/05 14:21:01 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			sort_dir(t_dir *dir, int order)
{
	t_dir	*head;
	int		i;
//TODO: just a test
//FIXME: klsdfghj

	i = 0;
	if (dir == NULL)
		return (1);
	head = dir;
	while (dir)
	{
		i = ft_strcmp(dir->direct, head->direct);
		order == 1 ? (i *= -1) : (i *= 1);
		if (i < 0)
			swap_name(&dir->direct, &head->direct);
		dir = dir->next;
		if (dir == NULL)
		{
			if (sort_dir(head->next, order))
				return (1);
		}
	}
	return (0);
}

void		swap_name(char **str, char **head)
{
	char	*tmp;

	tmp = *head;
	*head = *str;
	*str = tmp;
}
