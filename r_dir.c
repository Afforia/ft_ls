/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:24:07 by thaley            #+#    #+#             */
/*   Updated: 2019/03/18 15:00:16 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

/*
** man opendir, readdir, closedir, dirent 
*/

int		main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *files;

	dir = opendir(".");

	if (dir == NULL)
	{
		write(1, "error\n", 7);
		return (1);
	}
	while ((files = readdir(dir)) != NULL)
	{
		printf("d_name = %s\n", files->d_name); //name of the file or dir
		printf("d_namelen = %d\n", files->d_namlen);//len of string
		printf("d_type = %i\n", files->d_type); //mb can be used
		printf("d_seekoff = %lli\n", files->d_seekoff); //dont need
		printf("d_ino = %lli\n", files->d_ino);//dont need (im quet shure)
	}
	closedir(dir);
	return (0);
}
