/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 04:25:07 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 06:40:43 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		directory(char **argv, t_flag *flag, int i)
{
	t_dir	*drct;
	t_dir	*head;

	drct = crt_dir(NULL);
	head = drct;
	while (argv[i])
	{
		if (drct->drct)
		{
			drct->next = crt_dir(drct);
			drct = drct->next;
		}
		drct->drct = take_path(argv[i]);
		i++;
	}
	if (i == 1 || (flag->R && i == 2))
		drct->drct = ft_strdup("./");
	drct = head;
	take_dir(drct, flag);
}

char		*take_path(char *argv)
{
	char	*new;

	new = malloc(sizeof(char) + (ft_strlen(argv) + 1));
	new = ft_strcpy(new, argv);
	new = ft_strcat(new, "/");
	return (new);
}

void		take_dir(t_dir *drct, t_flag *flag)
{
	DIR				*dir;
	t_file			*names;
	t_file			*head;

	names = crt_file(NULL);
	head = names;
	if (flag->d_count > 1)
		sort_dir(drct);
	while (drct)
	{
		if ((dir = opendir(drct->drct)) == NULL)
		{
			ft_putstr(drct->drct);
			ft_putstr(" : no such file or directory.\n");
			drct = drct->next;
			continue;
		}
		take_names(dir, drct, names);
		closedir(dir);
		drct = drct->next;
	}
	sort_names(names);

	printf("%d\n", flag->d_count);
	while (names)
	{
		printf("%s\n", names->name);
		names = names->next;
	}
}

void		take_names(DIR *dir, t_dir *drct, t_file *names)
{
	struct dirent	*file;

	while ((file = readdir(dir)))
	{
		while (names->name)
		{
			while (names->next != NULL)
				names = names->next;
			names->next = crt_file(names);
			names = names->next;
		}
		names->d_name = ft_strdup(drct->drct);
		names->name = ft_strdup(file->d_name);
		names->type = file->d_type;
	}
}
