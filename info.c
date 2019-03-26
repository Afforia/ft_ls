/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:11:00 by thaley            #+#    #+#             */
/*   Updated: 2019/03/26 20:54:54 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* return 1 if smth wrong. 0 = all OK */
/* here must done all with 1 dir and ONLY then go to next */

int		get_info(DIR *dir, char *direct, t_flags *flag)
{
	t_ls			*ls;
	t_ls			*head;
	struct dirent	*file;
	
	ls = NULL;
	head = NULL;
	file = NULL;
	if ((dir = opendir(direct)) == NULL)
		return (1);
	ls = add_list(ls);
	head = ls;
	while ((file = readdir(dir)) != NULL)
	{
		if (ls->name)
		{
			ls->next = add_list(ls);
			ls = ls->next;
		}
		ls->name = ft_strdup(file->d_name);
	}
	ls = head;
	
	return (0);
}