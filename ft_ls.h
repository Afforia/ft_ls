/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:07:53 by thaley            #+#    #+#             */
/*   Updated: 2019/03/30 17:06:50 by thaley           ###   ########.fr       */
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

typedef struct		s_ls
{
	char			*name;
	char			*m_time;
	char			*sort_time;
	char			*user_name;
	char			*group_name;
	char			*acess;
	int				size;
	int				link;
	int				uid;
	int				count;
	long long int	block;
	struct s_ls		*next;
}					t_ls;

typedef struct		s_flags
{
	int				l;
	int				a;
	int				r;
	int				R;
	int				t;
}					t_flags;

typedef struct 		s_access
{
	char			*user;
	char			*group;
	char			*other;
	char			*type;
	struct s_access	*next;
}					t_access;

int					take_dir(char *argv, t_flags *flag);
int					take_flags(char *argv, t_flags *flag);
int					find_flag(t_flags *flag, char *argv);

int					write_info(char *direct, t_flags *flag);
int					write_name(t_ls *ls, DIR *dir);

t_flags				*creat_flag();
t_ls				*add_list(t_ls *head);

int					sort_string(t_ls *ls, t_flags *flag);
void				rm_dotf(t_ls *ls);
int					ascii_sort(t_ls *ls, int order);
int					take_stime(t_ls *ls);

int					print_ls(t_ls *ls, t_flags *flag);

#endif