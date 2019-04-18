/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:59:52 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 00:03:02 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*take_dir(char **argv, t_flag *flag)
{
	t_dir	*new;
	t_dir	*head;
	int		i;

	new = crt_dir(NULL);
	head = new;
	i = 1;
	flag = find_flag(argv, &i);
	if (argv[i])
	{
		while (argv[i])
		{
			new = wr_dir(argv[i], new);
			i++;
		}
	}
	else
	{
		new->count = 1;
		new->dirent = ft_strdup(".");
		new->len = 2; 
	}
	return (head);
}

t_dir		*wr_dir(char *argv, t_dir *dir)
{
	t_dir	*new;

	return (new);
}
