/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 07:45:29 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/17 07:45:30 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int	ft_start_end(char *line, t_num *num)
{
	if (ft_strcmp("##start", line) == 0)
	{
		(*num).phase = 1;
		(*num).index = 1;
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		(*num).phase = 1;
		(*num).index = 2;
	}
	return (0);
}

static	int	ft_add_ant(t_num *num, char **elem)
{
	if ((ft_valid_int(elem[0]) == -1) || (ft_atoi(elem[0])) < 0)
	{
		ft_free_double((void **)elem);
		return (-1);
	}
	if ((*num).phase == 0)
		(*num).n_ant = ft_atoi(elem[0]);
	else
	{
		ft_free_double((void **)elem);
		return (-1);
	}
	return (0);
}

static	int	ft_process(t_room **list, char *line, t_num *num)
{
	size_t	size;
	char	**elem;

	elem = ft_strsplit(line, ' ');
	size = ft_double_len((void **)elem);
	if (size == 3 && ((*num).phase == 0 || (*num).phase == 1
		|| (*num).phase == 2))
		ERROR((ft_process_room(list, num, elem)) == -1, -1);
	else if (size == 1)
	{
		if (ft_strchr(elem[0], '-') && ((*num).phase == 2 || (*num).phase == 3))
			ERROR((ft_process_link(list, num, line, elem)) == -1, -1);
		else
			ERROR((ft_add_ant(num, elem)) == -1, -1);
		ft_free_double((void **)elem);
	}
	else
	{
		ft_free_double((void **)elem);
		return (-1);
	}
	return (0);
}

int			ft_parse(t_room **list, t_num *num, char **line)
{
	if (ft_strstr(*line, "##"))
		FERROR(((ft_start_end(*line, num)) == -1), *line, -1);
	else if ((*line)[0] != 'L' && (*line)[0] != '#')
		FERROR(((ft_process(list, *line, num)) == -1), *line, -1);
	else if ((*line)[0] == 'L')
	{
		FREE(*line);
		return (-1);
	}
	FREE(*line);
	return (0);
}
