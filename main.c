/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 08:27:09 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/25 10:30:16 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>
#include <math.h>

t_board		*test(t_board *board, int *counter, char c)
{
	board->c = c;
	if (!is_valid(board->shape) || !(board->next = lst_addnew()))
		return (NULL);
	reform_shape_center(board->shape);
	(*counter)++;
	return (board->next);
}

int			validate_shape(int fd, t_board **start, int *counter)
{
	char		*line;
	t_board		*board;
	int			i;
	int			j;
	char		c;

	initial(&i, &c);
	if ((board = lst_addnew()) == NULL)
		return (0);
	*start = board;
	while (get_next_line(fd, &line) == 1 && !(j = 0))
	{
		if (++i == HEIGHT && (i = -1))
		{
			if (!(board = test(board, counter, c++)))
				return (0);
			continue;
		}
		while (*line)
			board->shape[i][j++] = (*line++ == BLOCK) ? 1 : 0;
	}
	if (!test(board, counter, c))
		return (0);
	board->next = NULL;
	return (1);
}

int			short_cut(char *line, int *nheight, int *nshape)
{
	while (*line && *nheight <= 4)
	{
		if (*line != BLOCK && *line != EMPTY)
			return (-1);
		if (*line++ == BLOCK)
			(*nshape)++;
	}
	return (1);
}

int			validate_file(int fd, char *argv, t_board **board, int *counter)
{
	char	*line;
	int		nheight;
	int		nshape;

	if (fd <= 1)
		return (-1);
	to_zero(&nheight, &nshape);
	while (get_next_line(fd, &line) == 1)
	{
		if (++nheight == HEIGHT + 1)
		{
			if (nshape != 4 || ft_strcmp(line, "") != 0)
				return (-1);
			to_zero(&nheight, &nshape);
			continue ;
		}
		if (ft_strlen(line) != WIDTH)
			return (-1);
		if (short_cut(line, &nheight, &nshape) == -1)
			return (-1);
	}
	if (nshape != 4 || !validate_shape(open_file(argv), board, counter))
		return (-1);
	return (1);
}

int			main(int argc, char **argv)
{
	t_board		*head;
	char		**table;
	int			counter;

	counter = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit	source_file\n");
		return (0);
	}
	if (validate_file(open_file(argv[1]), argv[1], &head, &counter) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	get_points(&head, 0, 0, 0);
	counter = (int)sqrt((counter + 1) * 4);
	table = initial_table(counter);
	while (solver(&head, table, &counter, init(0, 0)) == 0)
	{
		counter++;
		table = initial_table(counter);
	}
	print_solution(table, counter);
	return (0);
}
