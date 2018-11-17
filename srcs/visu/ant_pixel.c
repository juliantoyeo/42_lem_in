/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 03:03:53 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/27 03:03:55 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../includes/visu.h"
#include <math.h>

static int	ft_ant_init(t_dant *ant, char *str)
{
	int		fd;
	int		nlines;
	char	*line;

	nlines = 0;
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		nlines++;
		FREE(line);
	}
	if (close(fd) == -1)
		return (0);
	(*ant).tab = (int **)malloc(sizeof(int *) * nlines + 1);
	(*ant).tab[nlines] = NULL;
	(*ant).nrows = nlines;
	return (0);
}

static int	ft_fill_ant(t_dant *ant, char *line, int i)
{
	int		x;
	int		j;
	size_t	size;

	size = ft_strlen(line) / 2 + 1;
	(*ant).tab[i] = (int *)malloc(sizeof(int) * size);
	j = 0;
	x = 0;
	while (line[j])
	{
		if (line[j] != ' ')
		{
			if (line[j] == '0')
				(*ant).tab[i][x++] = 0x0;
			else if (line[j] == '1')
				(*ant).tab[i][x++] = GREY;
			else if (line[j] == '2')
				(*ant).tab[i][x++] = RED;
			else if (line[j] == '3')
				(*ant).tab[i][x++] = WHITE;
		}
		j++;
	}
	(*ant).ncols = size;
	return (0);
}

int			ft_create_ant_map(t_dant *ant, char *str)
{
	int		i;
	int		fd;
	char	*line;

	ft_ant_init(ant, str);
	i = 0;
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		ft_fill_ant(ant, line, i);
		i++;
		FREE(line);
	}
	if (close(fd) == -1)
		return (0);
	return (0);
}
