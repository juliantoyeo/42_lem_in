/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 07:52:53 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/17 07:52:55 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int	ft_check_room(t_room **list, char **elem, int index)
{
	t_room	*lst;

	lst = *list;
	while (lst)
	{
		if ((lst->index == 1 && index == 1) || (lst->index == 2 && index == 2))
			lst->index = 0;
		lst = lst->next;
	}
	lst = *list;
	while (lst)
	{
		if ((lst->x == ft_atoi(elem[1])) && (lst->y == ft_atoi(elem[2])))
			return (-1);
		if (lst->name == elem[0])
			return (-1);
		lst = lst->next;
	}
	return (0);
}

static	int	ft_add_room(t_room **list, char **elem, int index)
{
	t_room	*new;

	ERROR((ft_check_room(list, elem, index) == -1), -1);
	ERROR((new = (t_room *)malloc(sizeof(t_room))) == NULL, -1);
	new->name = ft_strdup(elem[0]);
	new->x = ft_atoi(elem[1]);
	new->y = ft_atoi(elem[2]);
	new->ant = 'n';
	new->visit = 'n';
	new->index = index;
	new->color = 0;
	new->from = NULL;
	new->next = NULL;
	new->link = NULL;
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
	ft_free_double((void **)elem);
	return (0);
}

int			ft_process_room(t_room **list, t_num *num, char **elem)
{
	if ((ft_valid_int(elem[1]) == -1) || (ft_valid_int(elem[2]) == -1))
	{
		ft_free_double((void **)elem);
		return (-1);
	}
	if (ft_strchr(elem[0], '-'))
	{
		ft_free_double((void **)elem);
		return (-1);
	}
	if ((ft_add_room(list, elem, (*num).index)) == -1)
	{
		ft_free_double((void **)elem);
		return (-1);
	}
	(*num).index = 0;
	(*num).phase = 2;
	return (0);
}
