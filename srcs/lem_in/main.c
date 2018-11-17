/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:22:09 by jyeo              #+#    #+#             */
/*   Updated: 2018/02/01 21:24:35 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_put_error(t_room *list, char *str)
{
	ft_putendl("ERROR");
	FREE(str);
	ft_free_list(&list);
	return (-1);
}

static int	ft_read_file(t_room **list, char **str, t_num *num)
{
	char	*line;
	char	*tmp;
	int		res;

	while ((res = get_next_line(0, &line)))
	{
		if (res == -1)
			return (-1);
		tmp = *str;
		FERROR((*str = ft_strjoin(*str, line)) == NULL, tmp, -1);
		FREE(tmp);
		tmp = *str;
		FERROR((*str = ft_strjoin(*str, "\n")) == NULL, tmp, -1);
		FREE(tmp);
		if ((ft_parse(list, num, &line) == -1))
			return (-1);
	}
	if ((*num).n_ant <= 0 || ft_check_valid(*list) == -1)
		return (-1);
	ft_printf("%s\n", *str);
	FREE(*str);
	return (0);
}

int			main(void)
{
	t_room	*list;
	t_num	num;
	t_ant	*a_list;
	size_t	size;
	char	*str;

	num.n_ant = 0;
	num.index = 0;
	num.phase = 0;
	list = NULL;
	ERROR((str = ft_strnew(0)) == NULL, -1);
	if ((ft_read_file(&list, &str, &num)) == -1)
		return (ft_put_error(list, str));
	size = ft_list_len(list);
	ft_init_ant(list, num.n_ant, size, &a_list);
	while ((ft_check_finish(a_list)) == -1)
		ft_solver(a_list, list, size);
	ft_free_ant(&a_list);
	ft_free_list(&list);
	return (0);
}
