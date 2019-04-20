/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:11:09 by thaley            #+#    #+#             */
/*   Updated: 2019/04/20 00:57:57 by thaley           ###   ########.fr       */
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
	int				R;
	int				d_count;
}					t_flag;

typedef struct		s_dir
{
	char			*drct;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_file
{
	char			*d_name;
	char			*name;
	unsigned int	type;
	struct s_file	*next;
}					t_file;


t_flag				*crt_flag(void);
t_dir				*crt_dir(t_dir *head);
t_file				*crt_file(t_file *head);

int					check_flag(char **argv, t_flag *flag);

void				directory(char **argv, t_flag *flag, int i);
char				*take_path(char *argv);
void				take_dir(t_dir *drct, t_flag *flag);
void				take_names(DIR *dir, char *drct, t_file *names, t_flag *flag);
void				sub_dir(t_file *head, t_flag *flag);

int					sort_dir(t_dir *drct);
int					sort_names(t_file *names);
void				change(char **str, char **str2);

#endif
