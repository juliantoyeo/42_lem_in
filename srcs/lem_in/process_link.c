/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 07:56:54 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/17 07:56:55 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int	ft_connect_room(t_room *room1, t_room *room2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (room1->link[i])
	{
		if (room1->link[i] == room2)
			return (-1);
		i++;
	}
	while (room2->link[j])
	{
		if (room2->link[j] == room1)
			return (-1);
		j++;
	}
	room1->link[i] = room2;
	room2->link[j] = room1;
	return (0);
}

static	int	ft_link(t_room **list, char *room1, char *room2)
{
	t_room	*lst;
	t_room	*lst2;

	lst = *list;
	lst2 = *list;
	while (lst)
	{
		if (ft_strcmp(lst->name, room1) == 0)
			break ;
		lst = lst->next;
	}
	while (lst2)
	{
		if (ft_strcmp(lst2->name, room2) == 0)
			break ;
		lst2 = lst2->next;
	}
	if (!lst || !lst2)
		return (-1);
	else
		ft_connect_room(lst, lst2);
	return (0);
}

static	int	ft_malloc_link(t_room **list, size_t size)
{
	t_room	*lst;
	int		i;

	lst = *list;
	while (lst)
	{
		i = 0;
		lst->link = (t_room **)malloc(sizeof(t_room) * ((int)size));
		while (i < ((int)size))
		{
			lst->link[i] = NULL;
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int			ft_process_link(t_room **list, t_num *num, char *line, char **elem)
{
	size_t	size;
	char	**room;

	room = ft_strsplit(line, '-');
	if ((*num).phase == 2)
	{
		size = ft_list_len(*list);
		ft_malloc_link(list, size);
		(*num).phase = 3;
	}
	size = ft_double_len((void **)room);
	if (size > 2 || (ft_link(list, room[0], room[1])) == -1)
	{
		ft_free_double((void **)room);
		ft_free_double((void **)elem);
		return (-1);
	}
	ft_free_double((void **)room);
	return (0);
}
