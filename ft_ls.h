/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:07:53 by thaley            #+#    #+#             */
/*   Updated: 2019/03/20 21:05:55 by thaley           ###   ########.fr       */
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

typedef struct	s_ls
{
	char			*name;
	char			*m_time;
	char			*user_name;
	char			*group_name;
	unsigned short	acess;
	int				size;
	int				link;
	int				uid;
	int				count;
	long long int	block;
	struct s_ls	*next;
}				t_ls;


t_ls			*some_func(DIR *dir);
t_ls			*add_list(t_ls *head);
void			free_list(t_ls **head, void del_ls(t_ls *));
void			del_ls(t_ls *tmp);
int				write_info(t_ls *info);
void			print_all(t_ls *info);
void			user_info(t_ls *info);
void			string_sort(t_ls *info);

#endif