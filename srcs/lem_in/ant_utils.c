/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:29:33 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/22 06:29:35 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_free_ant(t_ant **list)
{
	int		i;
	t_ant	*tmp;

	while (*list)
	{
		i = 0;
		tmp = *list;
		*list = (*list)->next;
		tmp->next = NULL;
		while (tmp->p[i])
		{
			FREE(tmp->p[i]);
			i++;
		}
		FREE(tmp->p);
		FREE(tmp);
	}
	*list = NULL;
	return (0);
}

int			ft_depath(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i + 1])
	{
		tmp = str[i];
		str[i] = ft_strdup(str[i + 1]);
		FREE(tmp);
		i++;
	}
	FREE(str[i]);
	return (0);
}

int			ft_reset_visit(t_room **list)
{
	t_room	*lst;

	lst = *list;
	while (lst)
	{
		lst->visit = 'n';
		lst = lst->next;
	}
	return (0);
}

int			ft_check_finish(t_ant *a_list)
{
	t_ant	*lst;

	lst = a_list;
	while (lst)
	{
		if (lst->room->index != 2)
			return (-1);
		lst = lst->next;
	}
	return (0);
}
