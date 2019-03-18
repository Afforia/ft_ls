/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:34:32 by thaley            #+#    #+#             */
/*   Updated: 2019/03/18 15:47:25 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int		main()
{
	struct	stat buf;
	size_t		len;
	char	tmp[256];
	stat("a.out", &buf);
	len = strlen((ctime(&buf.st_mtime)));
	strcpy(tmp, (ctime(&buf.st_mtime))); //modify time
	printf("cy = %s\n", tmp);
	printf("%li\n", len);
	return (0);
}