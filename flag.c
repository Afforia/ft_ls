/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:55:09 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 04:18:32 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_flag(char **argv, t_flag *flag)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'R')
			{
				ft_putstr("illegal option: -- ");
				ft_putchar(argv[i][j]);
				ft_putchar('\n');
				return (-1);
			}
			flag->R = 1;
			j++;
		}
		i++;
	}
	return (i);
}
