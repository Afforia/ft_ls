/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:11:09 by thaley            #+#    #+#             */
/*   Updated: 2019/04/11 22:17:32 by thaley           ###   ########.fr       */
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
	unsigned int	type;
	size_t			len;
	int				count;
	struct s_dir	*next;
}					t_dir;

typedef struct 		s_sort
{
	char			*m_time;
	char			*dir_name;
	char			*print_name;
	int				year;
	int				mnth;
	int				week;
	int				day;
	int				hour;
	int				min;
	int				sec;
}					t_sort;

typedef struct		s_access
{
	char			*user;
	char			*group;
	char			*other;
	char			*type;
}					t_access;

typedef struct		s_ls
{
	t_sort			*sort;
	t_access		*chmod;
	char			*print_time;
	char			*u_name;
	char			*g_name;
	char			*access;
	int				size;
	int				link;
	int				uid;
	long long int	blocks;
	struct s_ls		*next;
}					t_ls;



int					find_flag(t_flag *flag, char *argv);
t_dir				*take_dir(char *direct, t_dir *dir);
void				info(t_dir *dir, t_flag *flag);
t_ls				*take_name(t_dir *direct, int flag);
t_ls				*write_path(DIR *dir, t_dir *direct, int flag);

t_flag				*crt_flag();
t_dir				*crt_dir(t_dir *head);
t_ls				*add_ls(t_ls *head);

#endif