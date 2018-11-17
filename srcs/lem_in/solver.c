/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:30:13 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/22 06:30:15 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_create_ant(t_ant **a_list, int num, int size)
{
	t_ant	*new;
	int		i;

	while (num-- > 0)
	{
		ERROR((new = (t_ant *)malloc(sizeof(t_ant))) == NULL, -1);
		new->ant = num + 1;
		new->room = NULL;
		new->p = (char **)malloc(sizeof(char *) * (int)size);
		i = 0;
		while (i < (int)size)
			new->p[i++] = NULL;
		new->next = NULL;
		if (!(*a_list))
			*a_list = new;
		else
		{
			new->next = *a_list;
			*a_list = new;
		}
	}
	return (0);
}

int			ft_init_ant(t_room *list, int n_ant, size_t size, t_ant **a_list)
{
	int		i;
	char	*p[size];
	t_room	*start;
	t_ant	*a_lst;

	*a_list = NULL;
	start = NULL;
	ft_get_start_end(list, &start, 1);
	ft_get_path(list, start, size, p);
	ft_create_ant(a_list, n_ant, size);
	a_lst = *a_list;
	while (a_lst)
	{
		i = 0;
		while (p[i])
		{
			a_lst->p[i] = ft_strdup(p[i]);
			i++;
		}
		a_lst->room = start;
		a_lst = a_lst->next;
	}
	return (0);
}

int			ft_move_ant(t_room **lst, t_ant **a_lst, int phase)
{
	if ((*lst)->ant == 'n' || (*lst)->index == 2)
	{
		(*a_lst)->room->ant = 'n';
		(*lst)->ant = 'y';
		(*a_lst)->room = *lst;
		ft_printf("L%d-%s ", (*a_lst)->ant, (*a_lst)->room->name);
		ft_depath((*a_lst)->p);
		if (phase == 1)
			return (1);
	}
	else
		return (-1);
	return (0);
}

int			ft_reroute(t_room **list, t_ant **a_lst, size_t size)
{
	int		i;
	t_room	*lst;
	char	*p[size];

	if ((ft_get_path(*list, (*a_lst)->room, size, p)) != -1)
	{
		i = 0;
		while (p[i])
		{
			FREE((*a_lst)->p[i]);
			(*a_lst)->p[i] = ft_strdup(p[i]);
			i++;
		}
	}
	lst = *list;
	while (lst)
	{
		if (ft_strcmp(lst->name, (*a_lst)->p[0]) == 0)
			if ((ft_move_ant(&lst, a_lst, 1)) == 1)
				break ;
		lst = lst->next;
	}
	return (0);
}

int			ft_solver(t_ant *a_list, t_room *list, size_t size)
{
	t_ant	*a_lst;
	t_room	*lst;

	a_lst = a_list;
	while (a_lst)
	{
		if (a_lst->room->index != 2)
		{
			lst = list;
			while (lst)
			{
				if (ft_strcmp(lst->name, a_lst->p[0]) == 0)
				{
					if ((ft_move_ant(&lst, &a_lst, 0)) == -1)
						ft_reroute(&list, &a_lst, size);
					break ;
				}
				lst = lst->next;
			}
		}
		a_lst = a_lst->next;
	}
	ft_printf("\n");
	return (0);
}
