/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:00:38 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 00:01:19 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag		*find_flag(char **argv, int *i)
{
	t_flag		*new;
	int			j;

	j = 0;
	new = crt_flag();
	if (argv[*i][0] == '-' && *i == 1)
	{
		while (argv[*i] && argv[*i][0] == '-')
		{
			if ((j = check_flag(new, argv[*i])) != 0)
			{
				perror("illegal flag: ");
				ft_putchar(argv[*i][j]);
				return (new);
			}
			*i = *i + 1;
		}
	}
	return (new);
}

int			check_flag(t_flag *flag, char *argv)
{
	int		i;
	int		check;

	i = 1;
	while (argv[i])
	{
		check = 0;
		argv[i] == 'l' ? (flag->l = 1) : check++;
		argv[i] == 'a' ? (flag->a = 1) : check++;
		argv[i] == 'r' ? (flag->r = 1) : check++;
		argv[i] == 'R' ? (flag->R = 1) : check++;
		argv[i] == 't' ? (flag->t = 1) : check++;
		if (check == 5)
			return (i);
		i++;
	}
	return (0);
}
