#include <stdio.h>
#include <stdlib.h>

typedef struct		s_ls
{
	void			*data;
	struct s_ls		*next;
}					t_ls;

typedef struct 		s_date
{
	// int				year;
	// int				mnth;
	// int				day;
	// int				week;
	int				hour;
	int				min;
	int				sek;
}					t_date;

t_ls		*sort(t_ls *head, int order, t_ls *ls);
int			ft_datecmp(t_date *next, t_date *date);

t_ls	*crt_ls(t_ls *ls, int h, int m, int c)
{
	t_ls	*new;
	t_ls	*tmp;
	t_date	*buf;

	tmp = ls;
	new = malloc(sizeof(t_ls));
	new->data = malloc(sizeof(t_date));
	buf = new->data;
	buf->hour = h;
	buf->min = m;
	buf->sek = c;
	new->next = NULL;
	if (tmp == NULL)
		ls = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

void	print_ls(t_ls *ls)
{
	t_date	*date;
	while (ls)
	{
		date = ls->data;
		printf("%d : %d : %d\n", date->hour, date->min, date->sek);
		ls = ls->next;
	}
}

int		main()
{
	t_ls		*head;
	t_ls		*ls;
	void		*buf;
	int	i = 0;

	ls = crt_ls(ls, 15, 29, 51);
	head = ls;
	while (i < 2)
	{
		if (i == 1)
			ls->next = crt_ls(ls, 14, 45, 20);
		else
			ls->next = crt_ls(ls, 15, 9, 43);
		ls = ls->next; 
		i++;
	}
	ls = head;
	ls = sort(ls, 1, ls);
	print_ls(ls);
	return (0);
}

t_ls			*sort(t_ls *head, int order, t_ls *ls)
{
	t_ls	*head_buf;
	t_ls	*next_tmp;
	t_ls	*head_tmp;
	int		i;

	i = 0;
	head_buf = ls;
	head_tmp = head;
	while (head_buf->next)
	{
		i = ft_datecmp(head_buf->next->data, head_buf->data);
		order = 1 ? (i *= -1) : (i *= 1);
		if (i < 0)
		{
			 if (head_buf == head)
			 {
				 next_tmp = head_buf->next->next; 
				 head_buf = head_buf->next;
				 head_buf->next = head;
				 head_buf->next->next = next_tmp;
			 }
			//  else
			//  {
			// 	 next_tmp = head_buf->next;
			// 	while (head_tmp->next != head_buf)
			// 		head_tmp = head_tmp->next;
			// 	head_tmp->next = head_buf;
			// 	ls->next = next_tmp;
			// 	head_buf->next = ls;
			//  }
			 
		}
		head_buf = head_buf->next;
	}
	ls = head;
	return (ls);
}

int		ft_datecmp(t_date *next, t_date *date)
{

	if (date->hour == next->hour)
	{
		if (date->min == next->min)
			return (date->sek - next->sek);
		else
			return (date->min - next->min);
	}
	return (date->hour - next->hour);
}