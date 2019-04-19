/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:11:09 by thaley            #+#    #+#             */
/*   Updated: 2019/04/19 03:14:51 by thaley           ###   ########.fr       */
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
	int				dir_count;
}					t_flag;

typedef struct		s_dir
{
	char			*direct;
	size_t			len;
	struct s_dir	*next;
}					t_dir;

typedef struct 		s_sort
{
	unsigned int	type;
	char			*m_time;
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

typedef struct 		s_output
{
	char			*dir_name;
	char			**print;
	struct s_output	*next;
}					t_output;


t_dir				*take_dir(char **argv, t_flag **flag);
t_dir				*wr_dir(char *argv, t_dir *dir);
void				dir_content(t_dir *direct, t_flag *flag);

t_flag				*find_flag(char **argv, int *i);
int					check_flag(t_flag *flag, char *argv);

t_flag				*crt_flag(void);
t_dir				*crt_dir(t_dir *head);
t_ls				*crt_ls(t_ls *head);
t_sort				*crt_sort(void);
t_output			*crt_out(t_output *head);

int					sort_dir(t_dir *dir, int order);
void				swap_name(char **str, char **head);

t_ls				*take_name(DIR *dir, t_dir *direct, t_flag *flag);
void				output(t_ls *ls, t_flag *flag, char *direct, t_output *print);

#endif