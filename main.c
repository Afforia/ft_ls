/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:17:59 by thaley            #+#    #+#             */
/*   Updated: 2019/04/10 18:01:24 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_flag	*flag;
	t_dir	*dir;
	int		i;

	i = 1;
	flag = crt_flag();
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			if (find_flag(flag, argv[i]))
				return (-1);
		}
		else
			dir = take_dir(argv[i], flag);
		i++;
	}	
	if (argc == 1 || !dir)
		dir = take_dir(".", flag);
	return (0);
}

t_flag		*find_flag(t_flag *flag, char *argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		argv[i] == 'l' ? (flag->l = 1) : j++;
		argv[i] == 'a' ? (flag->a = 1) : j++;
		argv[i] == 'r' ? (flag->r = 1) : j++;
		argv[i] == 'R' ? (flag->R = 1) : j++;
		argv[i] == 't' ? (flag->t = 1) : j++;
		if (j == 5)
			return (1);
		i++;
	}
	return (0);
}

t_dir		*take_dir(char *direct, t_flag *flag)
{
	
}
