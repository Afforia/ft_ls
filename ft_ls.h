/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:07:53 by thaley            #+#    #+#             */
/*   Updated: 2019/03/27 20:54:50 by thaley           ###   ########.fr       */
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



char				**find_dir(char **argv, t_flags **flag);
t_flags				*find_flag(char *argv);

int					get_name(DIR *dir, char *direct, t_flags *flag);
int					get_info(t_ls *ls);
int					string_sort(t_ls *ls);
int					options(t_ls *ls, t_flags *flag);
void				user_info(t_ls *ls);
void				acess(t_ls *ls);

t_ls				*add_list(t_ls *head);
t_flags				*creat_flag();
t_access			*creat_access(t_ls *ls, t_access *head);

char				*ft_unitoa(unsigned short n);

// t_ls				*some_func(DIR *dir);
// void				free_list(t_ls **head, void del_ls(t_ls *));
// void				del_ls(t_ls *tmp);
// int					write_info(t_ls *info);
// void				print_all(t_ls *info);
// void				user_info(t_ls *info);
// int					string_sort(t_ls *info);

#endif