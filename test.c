/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:23:22 by thaley            #+#    #+#             */
/*   Updated: 2019/03/18 21:53:12 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h> //write | readlink
#include <dirent.h> //opendir | readdir | closedir
#include <sys/types.h> // structs
#include <sys/dir.h> //struct dirent
#include <sys/stat.h> //stat | lstat
#include <grp.h> //getgrgid
#include <uuid/uuid.h> //getgrgid | getpwuid
#include <sys/xattr.h> //listxattr | getxattr
#include <time.h> //time | ctime
#include <stdlib.h> //malloc | free | exit
#include <stdio.h> //perror | strerror

/*
** print time and name of file/dir (not as ls)
** sort by ascii
*/
void	print_all(char **name, char **f_time)
{
	int k = 0;
	while (name[k] != NULL)
	{
		ft_putstr(f_time[k]);
		write(1, " ", 1);
		ft_putstr(name[k]);
		write(1, "\n", 2);
		k++;
	}
	k = 0;
	char *tmp;
	tmp = name[k];
	while (k < 14)
	{
		free(name[k]);
		k++;
	}
	name[0] = tmp;
	free(name);
}
/*
** st_nlink = кол-во жестких связок, #2
** st_mtime = время послденей модификации, #6
** st_size = размер файла, #5
*/

char	**get_time(int index, char **name)
{
	struct stat		buf;
	char			**new;
	int				i;
	size_t			len;

	i = 0;
	len = 0;
	new = NULL;
	new = (char **)malloc(sizeof(char *) * index);
	while (i < index)
	{
		stat(name[i], &buf);
		printf("%s\n", ft_itoa((buf.st_nlink)));
		len = ft_strlen(ctime(&buf.st_mtime));
		printf("%2s || %2s\n", ctime(&buf.st_mtime), ft_itoa(buf.st_size));
		new[i] = (char *)malloc(sizeof(char) * len);
		new[i] = ft_strcpy(new[i], ctime(&buf.st_mtime));
		new[i][len - 1] = '\0';//remove \n at the and of time
		i++;
	}
	new[i] = NULL;
	return (new);
}

char	**get_string(int i, DIR *dir)
{
	struct dirent	*file;
	char			**name;

	name = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while ((file = readdir(dir)) != NULL)
	{
		name[i] = (char *)malloc(sizeof(char) * file->d_namlen);
		name[i] = ft_strcpy(name[i], file->d_name);
		i++;		
	}
	write(1, "\n", 1);
	name[i] = NULL;
	return (name);
}

int		count_files(DIR *dir)
{
	struct dirent	*file;
	int				i;

	i = 0;
	while((file = readdir(dir)) != NULL)
		i++;
	return (i);
}

int		main()
{
	DIR				*dir;
	char			**name;
	int				i;
	char			**f_time;

	i = 0;
	name = NULL;
	dir = opendir(".");
	if (dir == NULL)
	{
		write(1, "error\n", 7);
		exit (1);
	}
	if (!(i = count_files(dir)))
		exit (1);
	closedir(dir);
	dir = opendir(".");
	// printf("file names: %d\n", i);
	name = get_string(i, dir);
	closedir(dir);
	f_time = get_time(i, name);	
	print_all(name, f_time);
	return (0);
}
