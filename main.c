/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:28:17 by thaley            #+#    #+#             */
/*   Updated: 2019/03/26 20:18:59 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR		*dir;
	t_flags	*flag;
	char	**direct;
	
	flag = NULL;
	direct = NULL;
	dir = NULL;
	if (argc == 1)
		dir = opendir(".");
	else
	{
		if (!(direct = find_dir(argv, &flag)))
			return (1); //check flags, take name of directories
		int i = 0;
		while (direct[i]) //need check ! if direct > 1 printf name of dir
		{
			if ((get_info(dir, direct[i], flag)))
			{
				ft_putstr("ft_ls: ");
				ft_putstr(direct[i]);
				ft_putstr(": No such file or directory\n");
				exit(1);
			}
			i++;
		}
	}
	return (0);
}

char	**find_dir(char **argv, t_flags **flag)
{
	char	**new;
	int		i;
	int		check;

	i = 1;
	check = 1;
	new = NULL; 
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			if ((*flag = find_flag(argv[i])))
				check = i + 1;
			else
			{
				ft_putstr("ft_ls: illegal option\n"); //must write what option wrong!
				return (NULL);	
			}
		}
		i++;
	}
	i = 0;
	while (argv[check + i])
		i++;
	if (i > 0)
	{
		new = (char **)malloc(sizeof(char *) * i + 1);
		i = 0;
		while (argv[check])
		{
			new[i] = ft_strdup(argv[check]);
			check++;
			i++;
		}
		new[i] = NULL;
	}
	return (new);
}

/*
** seems to work correctly
*/

t_flags	*find_flag(char *argv)
{
	int		i;
	int		j;
	int		check;
	char tmp[5] = {'l', 'a', 'r', 'R', 't'};
	t_flags	*flag;

	i = 1;
	check = 0;
	if (!(flag = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flag->l = 0;
	flag->a = 0;
	flag->r = 0;
	flag->R = 0;
	flag->t = 0;
	while (argv[i])
	{
		check = 0;
		j = 0;
		if (argv[i] != 'l' && argv[i] != 'a' && argv[i] != 'r'
			&& argv[i] != 'R' && argv[i] != 't')
		{
			free(flag);
			return (NULL);
		}
		while (tmp[j])
		{
			if (argv[i] == tmp[j])
			{
				j == 0 ? (flag->l = 1) : check++;
				j == 1 ? (flag->a = 1) : check++;
				j == 2 ? (flag->r = 1) : check++;
				j == 3 ? (flag->R = 1) : check++;
				j == 4 ? (flag->t = 1) : check++;
			}
			j++;
		}
		i++;
	}
	return (flag);
}
