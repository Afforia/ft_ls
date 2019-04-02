/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:22:35 by thaley            #+#    #+#             */
/*   Updated: 2019/03/29 21:30:12 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ls(t_ls *ls, t_flags *flag, t_access *access, int blocks)
{
	if (flag->l == 1)
	{
		printf("total: %d\n", blocks);
		while (ls)
		{
			printf("%s", access->type);
			printf("%s", access->user);
			printf("%s", access->group);
			printf("%s ", access->other);
			printf("%d ", ls->link);
			printf("%-1s ", ls->user_name);
			printf("%-1s ", ls->group_name);
			printf("%5d ", ls->size);
			printf("%-1s ", ls->m_time);
			printf("%1s\n", ls->name);
			ls = ls->next;
			access = access->next;
		}
	}
	else if (flag->l == 0)
	{
		while (ls)
		{
			printf("%s  ", ls->name);
			ls = ls->next;
		}
		printf("\n");
	}
}