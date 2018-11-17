/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_visu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 07:17:21 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/28 07:17:23 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"

static int	ft_get_ant_vector(t_win *p, t_ant **ant)
{
	t_ant	*lst;
	t_cord	line;

	lst = *ant;
	line.x0 = (p->x) + (lst->room->x * 60) + 15;
	line.y0 = (p->y) + (lst->room->y * 60) + 15;
	line.x1 = (p->x) + (lst->dest->x * 60) + 15;
	line.y1 = (p->y) + (lst->dest->y * 60) + 15;
	lst->vx = line.x1 - line.x0;
	lst->vy = line.y1 - line.y0;
	lst->mag = sqrt((lst->vx * lst->vx) + (lst->vy * lst->vy));
	lst->inc_x = lst->vx / lst->mag;
	lst->inc_y = lst->vy / lst->mag;
	lst->posx = (p->x) + (lst->room->x * 60) + 15;
	lst->posy = (p->y) + (lst->room->y * 60) + 15;
	return (0);
}

static int	ft_get_move(t_win *p, t_room *list, t_ant **ant, char *move)
{
	int		n_ant;
	char	**elem;
	t_room	*dest;
	t_ant	*lst;

	dest = NULL;
	elem = ft_strsplit(move, '-');
	n_ant = ft_atoi(elem[0] + 1);
	ft_get_room(list, &dest, elem[1]);
	lst = *ant;
	while (lst)
	{
		if (lst->ant == n_ant)
		{
			lst->dest = dest;
			ft_get_ant_vector(p, &lst);
			ft_printf("im ant %d, from room %s, going to room %s\n",
					lst->ant, lst->room->name, lst->dest->name);
			break ;
		}
		lst = lst->next;
	}
	ft_free_double((void **)elem);
	return (0);
}

int			ft_get_next_move(t_win *p, t_room *list, t_ant **ant)
{
	int		i;
	char	*line;
	char	**move;

	i = 0;
	if ((get_next_line(0, &line)) == 0)
		return (-1);
	move = ft_strsplit(line, ' ');
	while (move[i])
	{
		ft_get_move(p, list, ant, move[i]);
		i++;
	}
	FREE(line);
	ft_free_double((void **)move);
	return (0);
}

static int	ft_init_ant_list(t_ant **new, t_room *start, int n_ant)
{
	(*new)->ant = n_ant + 1;
	(*new)->posx = 0;
	(*new)->posy = 0;
	(*new)->vx = 0;
	(*new)->vy = 0;
	(*new)->count = 0;
	(*new)->inc_x = 0;
	(*new)->inc_y = 0;
	(*new)->total_x = 0;
	(*new)->total_y = 0;
	(*new)->mag = 0;
	(*new)->room = start;
	(*new)->dest = NULL;
	(*new)->p = NULL;
	(*new)->next = NULL;
	return (0);
}

int			ft_create_ant_list(t_room *list, t_ant **ant, int n_ant)
{
	t_ant	*new;
	t_room	*start;

	ft_get_start_end(list, &start, 1);
	while (n_ant-- > 0)
	{
		ERROR((new = (t_ant *)malloc(sizeof(t_ant))) == NULL, -1);
		ft_init_ant_list(&new, start, n_ant);
		if (!(*ant))
			*ant = new;
		else
		{
			new->next = *ant;
			*ant = new;
		}
	}
	return (0);
}
