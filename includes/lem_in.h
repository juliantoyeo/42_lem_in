/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:20:19 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/01 21:21:09 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	unsigned char	visit;
	unsigned char	ant;
	int				index;
	int				color;
	struct s_room	*from;
	struct s_room	*next;
	struct s_room	**link;
}					t_room;

typedef	struct		s_num
{
	int				n_ant;
	int				index;
	int				phase;
}					t_num;

typedef	struct		s_ant
{
	int				ant;
	double			posx;
	double			posy;
	int				vx;
	int				vy;
	int				count;
	double			inc_x;
	double			inc_y;
	double			total_x;
	double			total_y;
	double			mag;
	struct s_room	*room;
	struct s_room	*dest;
	char			**p;
	struct s_ant	*next;
}					t_ant;

int					ft_free_list(t_room **list);
int					ft_free_ant(t_ant **list);
size_t				ft_list_len(t_room *list);
int					ft_free_link(t_room **list);
int					ft_get_start_end(t_room *list, t_room **room, int index);
int					ft_get_room(t_room *list, t_room **now, char *name);
int					ft_dequeue(char **str);
int					ft_depath(char **str);
int					ft_reset_visit(t_room **list);
int					ft_check_finish(t_ant *a_list);
int					ft_parse(t_room **list, t_num *num, char **line);
int					ft_process_room(t_room **list, t_num *num, char **elem);
int					ft_process_link(t_room **l, t_num *n, char *ln, char **el);
int					ft_check_valid(t_room *list);
int					ft_get_path(t_room *lst, t_room *st, size_t size, char **p);
int					ft_solver(t_ant *a_lst, t_room *lst, size_t size);
int					ft_init_ant(t_room *lst, int n, size_t size, t_ant **a_lst);

#endif
