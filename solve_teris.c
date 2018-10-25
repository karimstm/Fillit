/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_teris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdiab- <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:13:19 by zdiab-            #+#    #+#             */
/*   Updated: 2018/10/25 09:57:58 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_get_point(int *flag, int *i, int *first, int *counter)
{
	*flag = 0;
	*i = -1;
	*first = 0;
	*counter = 0;
}

char	**initial_table(int size)
{
	char	**table;
	int		i;
	int		j;

	table = (char **)malloc(sizeof(char *) * size);
	i = -1;
	while (++i < size)
	{
		table[i] = (char *)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < size)
			table[i][j++] = '.';
		table[i][j] = '\0';
	}
	return (table);
}

int		is_safe(char **table, t_point point, t_point corr[4], int size)
{
	int pos;

	pos = 0;
	while (pos < 4)
	{
		if (point.x + corr[pos].y >= size | point.y + corr[pos].x >= size)
			return (0);
		pos++;
	}
	if (((table[point.x + corr[0].y][point.y + corr[0].x] ^ '.') |
				(table[point.x + corr[1].y][point.y + corr[1].x] ^ '.')))
		return (0);
	if (((table[point.x + corr[2].y][point.y + corr[2].x] ^ '.') |
				(table[point.x + corr[3].y][point.y + corr[3].x] ^ '.')))
		return (0);
	return (1);
}

void	place_teris(char **table, int i, int j, t_board *brd)
{
	int pos;

	pos = 0;
	while (pos < 4)
	{
		table[i + brd->corrd[pos].y][j + brd->corrd[pos].x] = brd->c;
		pos++;
	}
}

void	remove_teris(char **table, int i, int j, t_point corr[4])
{
	int pos;

	pos = 0;
	while (pos < 4)
	{
		table[i + corr[pos].y][j + corr[pos].x] = '.';
		pos++;
	}
}
