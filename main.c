/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 08:27:09 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/17 11:50:27 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "includes/fillit.h"
#include <stdio.h>

void 	print_shape(t_board *board)
{
	int i;
	int j;

	while (board)
	{
		i = -1;
		while (i < 3)
		{
			j = 0;
			while (j < 4)
				printf("%d - ", board->shape[++i][j++]);
			printf("\n");
		}
		board = board->next;
	}	
}

int		open_file(char *file)
{
	int fd;

	if((fd = open(file, O_RDONLY)) <= 2)
		return (-1);
	return (fd);
}

int		validate_shape(int fd)
{
	char		*line;
	t_board		*board;
	t_board		*head;
	int 		i;
	int			j;

	i = 0;
	if ((board = lst_addnew()) == NULL)
		return (0);
	head = board;
	printf("something\n");
	while (get_next_line(fd, &line) == 1)
	{
		if (i == HEIGHT && (i = 0) == 0)
		{
			if ((board->next = lst_addnew()) == NULL)
				return (0);
			board = board->next;
			continue;
		}
		j = 0;
		while (*line)
		{
			board->shape[i][j++] = (*line == BLOCK) ? 1 : 0;
			line++;
		}
		i++;
	}
	board->next = NULL;
	print_shape(head);
	return (1);
}

int		validate_file(int fd, char *argv)
{
	char *line;
	int	nheight;

	nheight = 0;
	if(fd <= 2)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if (++nheight == HEIGHT + 1)
		{
			if (ft_strcmp(line, "") != 0)
				return (-1);
			nheight = 0;
			continue ;
		}
		if (ft_strlen(line) != WIDTH)
			return (-1);
		while (*line && nheight <= 4)
		{
			if (*line != BLOCK && *line != EMPTY)
				return (-1);
			line++;
		}
	}
	if (!validate_shape(open_file(argv)))
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("Usage: ./fillit	source_file", STDERR_FILENO);
	if(validate_file(open_file(argv[1]), argv[1]) == -1)
		ft_putstr_fd("error\n", STDERR_FILENO);
}
