/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 08:22:12 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/23 08:22:13 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include "mlx.h"
# include <math.h>
# define SCREEN_X 1500
# define SCREEN_Y 1500
# define LEMON 0xfffacd
# define LSEA 0x20b2aa
# define CYAN 0x00ffff
# define LCORAL 0xf08080
# define MROSE 0xffe4e1
# define LBLUE 0xadd8e6
# define PEACH 0xffdab9
# define DEW 0xf0fff0
# define LYELLOW 0xffffe0
# define MPURPLE 0x9370db
# define RED 0xff0000
# define WHITE 0xffffff
# define GREY 0x474747
# define SPEED 5
# define USLEEP 5000

typedef	struct		s_move
{
	int				x;
	int				y;
	int				click_x;
	int				click_y;
}					t_move;

typedef	struct		s_size
{
	int				i;
	int				x;
	int				y;
}					t_size;

typedef	struct		s_cord
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_cord;

typedef	struct		s_dline
{
	int				dx;
	int				dy;
	int				adj;
	int				diff;
}					t_dline;

typedef	struct		s_dant
{
	int				**tab;
	int				nrows;
	int				ncols;
}					t_dant;

typedef	struct		s_win
{
	int				c_x;
	int				c_y;
	int				x;
	int				y;
	int				color;
	int				mouse_press;
	int				loop;
	t_move			i;
	t_room			*list;
	t_dant			ant_1;
	t_dant			ant_1_2;
	t_dant			ant_2;
	t_dant			ant_2_2;
	t_num			num;
	t_ant			*ant;
	void			*mlx;
	void			*win;
}					t_win;

int					ft_free_exit(t_win *p);
int					ft_draw_ant(t_win *p, t_dant ant, int x, int y);
int					ft_draw_room(t_win *p, int x, int y);
int					ft_draw_line(t_win *p, t_cord line);
int					ft_create_ant_map(t_dant *ant, char *str);
int					ft_get_room_colour(t_win **p);
int					ft_read_line(t_win **p, t_num *num);
int					ft_draw_map(t_win *p);
int					ft_create_ant_list(t_room *list, t_ant **ant, int n_ant);
int					ft_get_next_move(t_win *p, t_room *list, t_ant **ant);
int					key_hook(int keycode, t_win *p);
int					mouse_hook(int bt, int x, int y, t_win *p);
int					mouse_hookup(int bt, int x, int y, t_win *p);
int					mouse_move(int x, int y, t_win *p);
int					update(t_win *p);

#endif
