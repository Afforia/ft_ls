/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:04:02 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 01:26:55 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_flag	*flag;
	t_dir	*direct;

	flag = NULL;
	if (argc == 1)
	{
		direct = crt_dir(NULL);
		direct->dirent = ft_strdup("./");
		direct->len = 3;
		flag = crt_flag();
		flag->dir_count = 1;
	}
	else
		direct = take_dir(argv, &flag);
	dir_content(direct, flag);
	return (0);
}
