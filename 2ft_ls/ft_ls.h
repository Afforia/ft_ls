/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:04:44 by thaley            #+#    #+#             */
/*   Updated: 2019/06/05 22:01:09 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

typedef struct			s_dir_data
{
	struct t_info		*info;
	struct s_dir_dat	*next;
}				t_dir_data;

typedef struct			s_flag
{
	int					l;
	int					a;
	int					t;
	int					r;
	int					R;
	int					dir_count;
	int					illegal;
}						t_flag;

struct					s_info
{
	char				*path;
	char				*dir;
	int					type;
}						;


int						take_flag(t_flag *flag, char **argv);
t_flag					*write_flag(t_flag *flag, char *argv);
char					*write_dname(char *argv);

#endif