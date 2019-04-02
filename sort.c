/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:39:07 by thaley            #+#    #+#             */
/*   Updated: 2019/03/30 17:17:02 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_string(t_ls *ls, t_flags *flag)
{
	if (!flag->a)
		rm_dotf(ls);
	// if (flag->t && flag->r)
	// 	time_sort(ls, 2);
	if (flag->t)
	{
		take_stime(ls);
		// time_sort(ls, 1);
	}
	else if (flag->r)
		ascii_sort(ls, 2);
	else
		ascii_sort(ls, 1);
	return (0);
}

void	rm_dotf(t_ls *ls)
{
	t_ls	*head;
	t_ls	*tmp;

	head = NULL;
	while (ls->name[0] == '.')
	{
		head = ls->next;
		free(ls->name);
		free(ls);
		ls = head;
	}
	tmp = ls;
	while (ls)
	{
		if (ls->name[0] == '.')
		{
			while (tmp && tmp->next != ls)
				tmp = tmp->next;
			tmp->next = ls->next;
			free(ls->name);
			free(ls);
			ls = tmp;
		}
		ls = ls->next;
	}
}

int		ascii_sort(t_ls *ls, int order)
{
	t_ls	*head;
	char	*tmp;
	int		i;
	int		check;

	i = 0;
	check = 0;
	tmp = NULL;
	if (ls == NULL)
		return (1);
	head = ls;
	while (ls)
	{
		i = ft_strcmp(ls->name, head->name);
		order == 1 ? (check = -1 * i) : (check = i);
		if (check > 0)
		{
			tmp = head->name;
			head->name = ls->name;
			ls->name = tmp;
		}
		ls = ls->next;
		if (ls == NULL)
		{
			if (ascii_sort(head->next, order))
				return (1);
		}
	}
	return (0);
}

// int		time_sort(t_ls *ls, int order)
// {
// 	return (0);
// }

int		take_stime(t_ls *ls)
{
	struct stat	buf;
	t_ls		*head;
	size_t		i;

	i = 0;
	head = ls;
	while (ls)
	{
		stat(ls->name, &buf);
		ls->sort_time = ft_strdup(ctime(&buf.st_mtime));
		printf("%s\n", ls->sort_time);
		ls = ls->next;
	}
	ls = head;
	while (ls)
	{
		i = ft_strlen(ls->sort_time);

	}
	return (0);
}
