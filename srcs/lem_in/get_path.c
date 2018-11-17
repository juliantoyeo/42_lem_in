/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:29:58 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/22 06:30:00 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_add_queue(char **q, char *name)
{
	int		i;

	i = 0;
	while (q[i])
		i++;
	q[i] = name;
	return (0);
}

static int	ft_init_q(t_room *start, size_t size, char **q)
{
	while (size)
		q[size--] = NULL;
	q[0] = start->name;
	start->visit = 'y';
	return (0);
}

static int	ft_get_shortest(t_room *list, size_t size, char **p, t_room *start)
{
	int		i;
	int		count;
	t_room	*now;
	t_room	*prev;

	prev = NULL;
	count = (int)size;
	while (size)
		p[size--] = NULL;
	ft_get_start_end(list, &now, 2);
	p[0] = now->name;
	i = 0;
	while (now->from != start)
	{
		if ((prev == now->from) || now->from->index == 1 || i > count)
			return (-1);
		prev = now;
		p[++i] = now->from->name;
		now = now->from;
	}
	ft_double_rev((void **)p);
	i = 0;
	return (0);
}

int			ft_get_path(t_room *list, t_room *start, size_t size, char **p)
{
	t_room	*now;
	int		i;
	char	*q[size];

	ft_init_q(start, size, q);
	ft_reset_visit(&list);
	while (q[0])
	{
		i = 0;
		ft_get_room(list, &now, q[0]);
		while (now->link[i])
		{
			if (now->link[i]->visit == 'n' && now->link[i]->ant == 'n'
				&& now->link[i]->index != 1)
			{
				now->link[i]->visit = 'y';
				now->link[i]->from = now;
				ft_add_queue(q, now->link[i]->name);
			}
			i++;
		}
		ft_dequeue(q);
	}
	ERROR((ft_get_shortest(list, size, p, start)) == -1, -1);
	return (0);
}
