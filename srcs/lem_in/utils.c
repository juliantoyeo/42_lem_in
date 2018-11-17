/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 05:10:12 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/17 05:10:13 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_free_list(t_room **list)
{
	t_room	*lst;
	t_room	*tmp;

	lst = *list;
	while (lst)
	{
		if (lst->link)
			FREE(lst->link);
		lst = lst->next;
	}
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->next = NULL;
		FREE(tmp->name);
		FREE(tmp);
	}
	*list = NULL;
	return (0);
}

size_t		ft_list_len(t_room *list)
{
	size_t	size;
	t_room	*lst;

	size = 0;
	lst = list;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int			ft_get_start_end(t_room *list, t_room **room, int index)
{
	t_room	*lst;

	lst = list;
	while (lst)
	{
		if (lst->index == index)
			break ;
		lst = lst->next;
	}
	*room = lst;
	return (0);
}

int			ft_get_room(t_room *list, t_room **now, char *name)
{
	t_room	*lst;

	lst = list;
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
			break ;
		lst = lst->next;
	}
	*now = lst;
	return (0);
}

int			ft_dequeue(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		str[i] = str[++j];
		i++;
	}
	return (0);
}
