/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 07:06:29 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/28 07:06:31 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"

int			ft_get_room_colour(t_win **p)
{
	int		*tab;
	t_room	*lst;

	tab = (int[10]){LBLUE, PEACH, LYELLOW, DEW, MPURPLE, LEMON, LSEA, CYAN,
		LCORAL, MROSE};
	lst = (*p)->list;
	while (lst)
	{
		if (lst->index == 1)
			lst->color = 0xff7f;
		else if (lst->index == 2)
			lst->color = 0xffa07a;
		else
			lst->color = tab[rand() % 10];
		lst = lst->next;
	}
	return (0);
}

int			ft_read_line(t_win **p, t_num *num)
{
	char	*line;

	(*num).n_ant = 0;
	(*num).index = 0;
	(*num).phase = 0;
	(*p)->list = NULL;
	while (get_next_line(0, &line))
	{
		if (line[0] == '\0')
		{
			FREE(line);
			break ;
		}
		if ((ft_parse(&(*p)->list, num, &line) == -1))
			return (-1);
	}
	return (0);
}

static int	ft_draw_tunnel(t_win *p)
{
	int		i;
	t_room	*lst;
	t_cord	line;

	lst = p->list;
	while (lst)
	{
		i = 0;
		while (lst->link[i])
		{
			p->color = lst->color;
			line.x0 = (p->x) + (lst->x * 60) + 25;
			line.y0 = (p->y) + (lst->y * 60) + 25;
			line.x1 = (p->x) + (lst->link[i]->x * 60) + 25;
			line.y1 = (p->y) + (lst->link[i]->y * 60) + 25;
			ft_draw_line(p, line);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int			ft_draw_map(t_win *p)
{
	t_room	*lst;

	ft_draw_tunnel(p);
	lst = p->list;
	while (lst)
	{
		p->color = lst->color;
		ft_draw_room(p, (p->x) + (lst->x * 60), (p->y) + (lst->y * 60));
		mlx_string_put(p->mlx, p->win, (p->x) + (lst->x * 60),
			(p->y) + (lst->y * 60), 0x000000, lst->name);
		if (lst->index == 1)
			mlx_string_put(p->mlx, p->win, (p->x) + (lst->x * 60),
				(p->y) + (lst->y * 60) + 15, 0x000000, "start");
		if (lst->index == 2)
			mlx_string_put(p->mlx, p->win, (p->x) + (lst->x * 60),
				(p->y) + (lst->y * 60) + 15, 0x000000, "end");
		lst = lst->next;
	}
	return (0);
}
