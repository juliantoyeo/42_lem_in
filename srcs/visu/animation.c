/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 08:01:17 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/28 08:01:20 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"

static int	ft_reach_dest(t_ant *ant)
{
	t_ant	*lst;
	int		res;

	res = 0;
	lst = ant;
	while (lst)
	{
		if (lst->dest != NULL)
			res = -1;
		lst = lst->next;
	}
	return (res);
}

static int	ft_animation(t_win *p, t_ant **ant)
{
	t_ant	*lst;

	lst = *ant;
	lst->posx += lst->inc_x * SPEED;
	lst->posy += lst->inc_y * SPEED;
	if (lst->room->x > lst->dest->x)
	{
		if (lst->count < 5)
			ft_draw_ant(p, p->ant_2, (int)lst->posx, (int)lst->posy);
		else if (lst->count < 10)
			ft_draw_ant(p, p->ant_2_2, (int)lst->posx, (int)lst->posy);
	}
	else
	{
		if (lst->count < 5)
			ft_draw_ant(p, p->ant_1, (int)lst->posx, (int)lst->posy);
		else if (lst->count < 10)
			ft_draw_ant(p, p->ant_1_2, (int)lst->posx, (int)lst->posy);
	}
	lst->count++;
	if (lst->count == 10)
		lst->count = 0;
	lst->total_x += lst->inc_x * SPEED;
	lst->total_y += lst->inc_y * SPEED;
	return (0);
}

static int	ft_process(t_win *p, t_ant **ant)
{
	t_ant	*lst;

	lst = *ant;
	if (lst->dest != NULL)
	{
		ft_animation(p, ant);
		if (abs((int)lst->total_x) >= abs((int)lst->vx) &&
			abs((int)lst->total_y) >= abs((int)lst->vy))
		{
			lst->room = lst->dest;
			lst->dest = NULL;
			lst->total_x = 0;
			lst->total_y = 0;
		}
	}
	else if (lst->dest == NULL)
		ft_draw_ant(p, p->ant_1, (p->x) + (lst->room->x * 60) + 15,
			(p->y) + (lst->room->y * 60) + 15);
	return (0);
}

int			update(t_win *p)
{
	t_ant	*lst;

	if (p->loop == 0)
		return (-1);
	if ((ft_reach_dest(p->ant)) == 0)
	{
		if ((ft_get_next_move(p, p->list, &p->ant)) == -1)
			return (-1);
	}
	mlx_clear_window(p->mlx, p->win);
	ft_draw_map(p);
	lst = p->ant;
	usleep(USLEEP);
	while (lst)
	{
		ft_process(p, &lst);
		lst = lst->next;
	}
	return (0);
}
