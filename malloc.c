/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 03:52:12 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 03:54:32 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag		*crt_flag(void)
{
	t_flag	*new;

	if (!(new = malloc(sizeof(t_flag))))
	{
		perror("don't allocate memory\n");
		return (NULL);
	}
	new->d_count = 0;
	new->R = 0;
	return (new);
}