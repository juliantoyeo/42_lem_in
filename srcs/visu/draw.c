/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 02:51:19 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/27 02:51:21 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"
#include <math.h>

int			ft_draw_ant(t_win *p, t_dant ant, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < ant.nrows)
	{
		j = 0;
		while (j < ant.ncols)
		{
			if (ant.tab[i][j] != 0x0)
				mlx_pixel_put(p->mlx, p->win, x + j, y + i, ant.tab[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_draw_room(t_win *p, int x, int y)
{
	int		count_x;
	int		count_y;
	int		next_x;
	int		next_y;

	count_x = 0;
	next_x = x + 50;
	next_y = y + 50;
	while (count_x < 50)
	{
		count_y = 0;
		while (count_y < 50)
			mlx_pixel_put(p->mlx, p->win, x + count_x, y + count_y++, p->color);
		count_x++;
	}
	return (0);
}

static int	ft_draw_line_low(t_win *p, t_cord line)
{
	int		y;
	t_dline	dline;

	dline.dx = line.x1 - line.x0;
	dline.dy = line.y1 - line.y0;
	dline.adj = 1;
	if (dline.dy < 0)
	{
		dline.adj = -1;
		dline.dy = -dline.dy;
	}
	dline.diff = (2 * dline.dy) - dline.dx;
	y = line.y0;
	while (line.x0 < line.x1)
	{
		mlx_pixel_put(p->mlx, p->win, line.x0, y, p->color);
		if (dline.diff > 0)
		{
			y = y + dline.adj;
			dline.diff = dline.diff - (2 * dline.dx);
		}
		dline.diff = dline.diff + (2 * dline.dy);
		line.x0++;
	}
	return (0);
}

static int	ft_draw_line_high(t_win *p, t_cord line)
{
	int		x;
	t_dline	dline;

	dline.dx = line.x1 - line.x0;
	dline.dy = line.y1 - line.y0;
	dline.adj = 1;
	if (dline.dx < 0)
	{
		dline.adj = -1;
		dline.dx = -dline.dx;
	}
	dline.diff = (2 * dline.dx) - dline.dy;
	x = line.x0;
	while (line.y0 < line.y1)
	{
		mlx_pixel_put(p->mlx, p->win, x, line.y0, p->color);
		if (dline.diff > 0)
		{
			x = x + dline.adj;
			dline.diff = dline.diff - (2 * dline.dy);
		}
		dline.diff = dline.diff + (2 * dline.dx);
		line.y0++;
	}
	return (0);
}

int			ft_draw_line(t_win *p, t_cord line)
{
	if (abs(line.y1 - line.y0) < abs(line.x1 - line.x0))
	{
		if (line.x0 > line.x1)
			ft_draw_line_low(p, line);
		else
			ft_draw_line_low(p, line);
	}
	else
	{
		if (line.y0 > line.y1)
			ft_draw_line_high(p, line);
		else
			ft_draw_line_high(p, line);
	}
	return (0);
}
