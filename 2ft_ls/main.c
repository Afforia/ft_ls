/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:04:23 by thaley            #+#    #+#             */
/*   Updated: 2019/06/05 22:01:40 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_dir_data	*dir_data;
	t_flag		*flag;
	int			i;

	dir_data = (t_dir_data *)malloc(sizeof(t_dir_data) + 1);
	dir_data->info = (s_info *)malloc(sizeof(s_info) + 1); //TODO: как сука выделить память?!
	flag = (t_flag *)malloc(sizeof(t_flag) + 1);

	/*
	** обнуляю все компоненты в структурах
	*/

	ft_bzero(dir_data, (sizeof(t_dir_data)));
	ft_bzero(flag, (sizeof(t_flag)));
	// ft_bzero(dir_data->info, sizeof(t_info));

	//TODO: проверить в школе как работает ls с аргументами "--", "---", "--a", "---a"
	
	/*
	** поиск флага, вывод ошибки при неправильном флаге
	*/

	//TODO: убедиться что если после флага нет аргументов argv возвращает null
	i = take_flag(flag, argv);
	printf("%i %s\n", i, argv[i]);
	if (argv[i] == NULL)
		dir_data->info;
	else
	{
		while (argv[i])
		{
			flag->dir_count++;
			i++;
		}
	}
	// printf("argv = %s, a = %i\n", *argv, flag->a);
	return (0);
}
