/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 08:01:28 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/23 08:01:31 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"

int		ft_free_ant(t_ant **list)
{
	t_ant	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->next = NULL;
		FREE(tmp->p);
		FREE(tmp);
	}
	*list = NULL;
	return (0);
}

int		ft_free_exit(t_win *p)
{
	mlx_destroy_window(p->mlx, p->win);
	ft_free_list(&p->list);
	ft_free_ant(&p->ant);
	ft_free_double((void **)p->ant_1.tab);
	ft_free_double((void **)p->ant_2.tab);
	ft_free_double((void **)p->ant_1_2.tab);
	ft_free_double((void **)p->ant_2_2.tab);
	FREE(p);
	return (0);
}

int		ft_init(t_win **p)
{
	*p = (t_win *)malloc(sizeof(t_win));
	(*p)->x = SCREEN_X / 8;
	(*p)->y = SCREEN_Y / 8;
	(*p)->c_x = (*p)->x;
	(*p)->c_y = (*p)->y;
	(*p)->mlx = mlx_init();
	(*p)->win = mlx_new_window((*p)->mlx, SCREEN_X, SCREEN_Y, "lem_in visu");
	(*p)->color = 0xFFFFFF;
	(*p)->mouse_press = 0;
	(*p)->loop = 0;
	(*p)->i.x = 0;
	(*p)->i.y = 0;
	(*p)->i.click_x = 0;
	(*p)->i.click_y = 0;
	ft_read_line(p, &(*p)->num);
	ft_get_room_colour(p);
	ft_create_ant_map(&(*p)->ant_1, "ant_pixel/ant_1.txt");
	ft_create_ant_map(&(*p)->ant_1_2, "ant_pixel/ant_1_2.txt");
	ft_create_ant_map(&(*p)->ant_2, "ant_pixel/ant_2.txt");
	ft_create_ant_map(&(*p)->ant_2_2, "ant_pixel/ant_2_2.txt");
	ft_create_ant_list((*p)->list, &(*p)->ant, (*p)->num.n_ant);
	return (0);
}

int		main(void)
{
	t_win	*p;

	ft_init(&p);
	ft_draw_map(p);
	mlx_key_hook(p->win, key_hook, (void *)p);
	mlx_mouse_hook(p->win, mouse_hook, (void *)p);
	mlx_hook(p->win, 5, 1L << 3, mouse_hookup, (void *)p);
	mlx_hook(p->win, 6, 1L << 6, mouse_move, (void *)p);
	mlx_loop_hook(p->mlx, update, (void *)p);
	mlx_loop(p->mlx);
	return (0);
}
