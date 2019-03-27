/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_dir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:24:07 by thaley            #+#    #+#             */
/*   Updated: 2019/03/27 18:31:59 by thaley           ###   ########.fr       */
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
		printf("d_namelen = %o\n", files->d_reclen);//len of string
		printf("d_type = %i\n", files->d_type); //mb can be used
		printf("d_ino = %li\n", files->d_ino);//dont need (im quet shure)
		printf("%li\n", files->d_off);
	}
	closedir(dir);
	return (0);
}
