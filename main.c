/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:34:32 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 05:15:40 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_flag	*flag;
	int		i;
	int		j;

	i = 0;
	j = 1;
	flag = crt_flag();
	if (argc == 1)
		flag->d_count = 1;
	else
	{
		if ((j = check_flag(argv, flag)) < 0)
			return (1);
		while (argv[i + j])
		{
			flag->d_count++;
			i++;
		}
		if (i + j == 2)
			flag->d_count = 1;
	}
	directory(argv, flag, j);
	return (0);
}
