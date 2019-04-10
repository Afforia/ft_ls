/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:11:09 by thaley            #+#    #+#             */
/*   Updated: 2019/04/10 17:58:08 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h> //write | readlink
# include <dirent.h> //opendir | readdir | closedir
# include <sys/types.h> // structs
# include <sys/dir.h> //struct dirent
# include <sys/stat.h> //stat | lstat
# include <grp.h> //getgrgid
# include <uuid/uuid.h> //getgrgid | getpwuid
# include <sys/xattr.h> //listxattr | getxattr
# include <time.h> //time | ctime
# include <stdlib.h> //malloc | free | exit
# include <stdio.h> //perror | strerror
# include <pwd.h> 

typedef struct		s_flag
{
	int				l;
	int				a;
	int				t;
	int				r;
	int				R;
}					t_flag;

typedef struct		s_dir
{
	char			*direct;
	int				count;
	struct s_dir	*next;
}					t_dir;

t_flag				*find_flag(t_flag *flag, char *argv);
t_dir				*take_dir(char *direct, t_flag *flag);

t_flag				*creat_flag();

#endif