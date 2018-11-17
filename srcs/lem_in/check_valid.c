/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 08:11:05 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/17 08:11:10 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int	ft_possible(t_room *list, t_room *room)
{
	int		i;

	i = 0;
	if (room->index == 2)
		return (1);
	while (room->link[i])
	{
		room->visit = 'y';
		while (room->link[i] && room->link[i]->visit == 'y')
			i++;
		if (!(room->link[i]))
			return (-1);
		if (ft_possible(list, room->link[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_check_link(t_room *list)
{
	t_room	*lst;
	int		i;

	lst = list;
	while (lst)
	{
		if (!lst->link)
			return (-1);
		else
		{
			i = 0;
			while (lst->link[i])
				i++;
			if (i == 0)
				return (-1);
		}
		lst = lst->next;
	}
	return (0);
}

static	int	ft_check_valid_map(t_room *list)
{
	t_room	*lst;
	int		i;
	char	end;
	char	start;

	i = 0;
	lst = list;
	end = 'n';
	start = 'n';
	if (lst == NULL)
		return (-1);
	while (lst)
	{
		if (lst->index == 2)
			end = 'y';
		if (lst->index == 1)
			start = 'y';
		i++;
		lst = lst->next;
	}
	if (end == 'n' || start == 'n')
		return (-1);
	return (0);
}

int			ft_check_valid(t_room *list)
{
	int		res;
	t_room	*start;

	ft_get_start_end(list, &start, 1);
	if (ft_check_valid_map(list) == -1)
		return (-1);
	if (ft_check_link(list) == -1)
		return (-1);
	res = ft_possible(list, start);
	if (res == -1 || res == 0)
		return (-1);
	ft_reset_visit(&list);
	return (0);
}
