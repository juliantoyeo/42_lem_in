/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 07:29:12 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/28 07:29:15 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"

int		key_hook(int keycode, t_win *p)
{
	ft_printf("the key is : %d \n", keycode);
	if (keycode == 53 || keycode == 82)
	{
		ft_free_exit(p);
		exit(0);
	}
	if (keycode == 8 || keycode == 49)
	{
		p->x = p->c_x;
		p->y = p->c_y;
		mlx_clear_window(p->mlx, p->win);
		ft_draw_map(p);
	}
	if (keycode == 36)
	{
		if (p->loop == 0)
			p->loop = 1;
		else if (p->loop == 1)
			p->loop = 0;
	}
	return (0);
}

int		mouse_hook(int bt, int x, int y, t_win *p)
{
	if (bt == 1)
		p->mouse_press = 1;
	if (bt == 1)
	{
		p->i.click_x = x;
		p->i.click_y = y;
	}
	return (0);
}

int		mouse_hookup(int bt, int x, int y, t_win *p)
{
	x = 0;
	y = 0;
	if (bt == 1)
		p->mouse_press = 0;
	return (0);
}

int		mouse_move(int x, int y, t_win *p)
{
	if (p->mouse_press == 1)
	{
		p->i.x = (x - p->i.click_x);
		p->i.y = (y - p->i.click_y);
		p->x += (p->i.x);
		p->y += (p->i.y);
		mlx_clear_window(p->mlx, p->win);
		ft_draw_map(p);
		p->i.click_x = x;
		p->i.click_y = y;
	}
	if (p->mouse_press == 0)
	{
		p->i.x = 0;
		p->i.y = 0;
	}
	return (0);
}
