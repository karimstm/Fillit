/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 08:27:09 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/24 11:31:21 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "includes/fillit.h"
#include <stdio.h>
#include <math.h>

int			is_valid(int shape[4][4])
{
	int i;
	int j;
	int point;

	i = 0;
	point = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i < 3 && (shape[i][j] & 1) & (shape[i + 1][j] & 1))
				point++;
			if (j < 3 && (shape[i][j] & 1) & (shape[i][j + 1] & 1))
				point++;
			j++;
		}
		i++;
	}
	if (point >= 3)
		return (1);
	return (0);
}

int			open_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) <= 2)
		return (-1);
	return (fd);
}

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

	i = -1;
	c = 'A';
	if ((board = lst_addnew()) == NULL)
		return (0);
	*start = board;
	while (get_next_line(fd, &line) == 1 && !(j = 0))
	{
		if (++i == HEIGHT && (i = -1))
		{
			if (!(board = test(board, counter, c++)))
				return (-1);
			continue;
		}
		while (*line)
			board->shape[i][j++] = (*line++ == BLOCK) ? 1 : 0;
	}
	if (!test(board, counter, c))
		return (-1);
	board->next = NULL;
	return (1);
}

int			validate_file(int fd, char *argv, t_board **board, int *counter)
{
	char *line;
	int	nheight;
	int nshape;

	nheight = 0;
	nshape = 0;
	if (fd <= 2)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if (++nheight == HEIGHT + 1)
		{
			if (nshape != 4 || ft_strcmp(line, "") != 0)
				return (-1);
			nheight = 0;
			nshape = 0;
			continue ;
		}
		if (ft_strlen(line) != WIDTH)
			return (-1);
		while (*line && nheight <= 4)
		{
			if (*line != BLOCK && *line != EMPTY)
				return (-1);
			if (*line++ == BLOCK)
				nshape++;
		}
	}
	if (nshape != 4 || !validate_shape(open_file(argv), board, counter))
		return (-1);
	return (1);
}

int			main(int argc, char **argv)
{
	t_board		*head;
	char		**table;
	int			counter = 0;

	if (argc != 2)
		ft_putstr_fd("Usage: ./fillit	source_file", STDERR_FILENO);
	if(validate_file(open_file(argv[1]), argv[1], &head, &counter) == -1)
	{
		ft_putstr_fd("error\n", STDERR_FILENO);
		exit(0);
	}
	get_points(&head);
	table = (char **)malloc(sizeof(char *) * counter);
	if (table == NULL)
		exit(0);	
	counter = (int)sqrt((counter + 1) * 4);
	table = initial_table(counter);
	while (solver(&head, table, &counter,0, 0) == 0)
	{
		counter++;
		table = initial_table(counter);
	}
	print_solution(table, counter);
	return (0);
}
