/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:53:58 by thaley            #+#    #+#             */
/*   Updated: 2019/03/18 22:08:44 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft/libft.h"
#include <unistd.h> //write | readlink
#include <dirent.h> //opendir | readdir | closedir
#include <sys/types.h> // structs
#include <sys/dir.h> //struct dirent
#include <sys/stat.h> //stat | lstat
#include <grp.h> //getgrgid
#include <uuid/uuid.h> //getgrgid | getpwuid
#include <pwd.h>
#include <sys/xattr.h> //listxattr | getxattr
#include <time.h> //time | ctime
#include <stdlib.h> //malloc | free | exit
#include <stdio.h> //perror | strerror

int		main()
{
	struct	passwd *buf;
	char	tmp[100];
	buf = getpwuid(0);
	printf("%s\n", buf->pw_dir);
	return (0);
}