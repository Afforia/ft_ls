/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:32:53 by thaley            #+#    #+#             */
/*   Updated: 2019/04/10 17:34:32 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag	*creat_flag()
{
	t_flag	*flag;

	flag = NULL;
	{
		if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
			return (NULL);
		flag->l = 0;
		flag->a = 0;
		flag->r = 0;
		flag->R = 0;
		flag->t = 0;
	}
	return (flag);
}