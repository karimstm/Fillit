/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:58:46 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/23 11:13:41 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "includes/fillit.h"
#include <stdio.h>

char     **initial_table(int size)
{
	char **table = (char **)malloc(sizeof(char *) * size);
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		table[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
			table[i][j++] = '.';
	}
	print_solution(table, size);
	return (table);
}

int		is_safe(char **table, int i, int j, t_point corr[4], int size)
{
	int pos = 0;
	while (pos < 4)
	{
		if (i + corr[pos].y >= size || j + corr[pos].x >= size)
			return (0);
		pos++;
	}
	if ((table[i + corr[0].y][j + corr[1].x] != '.' ||
				table[i + corr[1].y][j + corr[1].x] != '.'))
		return (0);
	if ((table[i + corr[2].y][j + corr[2].x] != '.' ||
				table[i + corr[3].y][j + corr[3].x] != '.'))
		return (0);
	return (1);
}

void	place_teris(char **table, int i, int j, t_point corr[4], char c)
{
	int pos;

	pos = 0;
	while (pos < 4)
	{
		table[i + corr[pos].y][j + corr[pos].x] = c;
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

void	print_solution(char **table, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%c", table[i][j++]); 
		}
		i++;
		printf("\n");
	}
}
int		solve_teris(t_board **board, char **table, int size, int *i, int *j)
{
	t_board *tmp;
	int x;
	int y;

	tmp = *board;
	x = *i;
	y = *j;
	while (x < size)
	{
		while (y < size)
		{
			if (table[x][y] == '.')
				if(is_safe(table, x, y, tmp->corrd, size))
				{
					place_teris(table, x, y, tmp->corrd, tmp->c);
					*j = y;
					*i = x;
					return (1);
				}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int     solver(t_board **board, char **table, int *counter, int x, int y)
{
	t_board *tmp;
	tmp = *board;



	int i;
	int j;

	i = x;
	j = y;
	if (i == (*counter) - 1 && i == (*counter) - 1)
		return (0);
	if (tmp == NULL)
		return (1);
	if(solve_teris(&tmp, table, *counter, &i, &j) == 0)
		return (0);
	if (solver(&tmp->next, table, counter, 0, 0) == 0)
	{
		remove_teris(table, i, j, tmp->corrd);
		if(++j == (*counter))
		{
			i++;
			j = 0;
		}
		return(solver(&tmp, table, counter, i, j));
	}else{
		return (1);
	}
	return (1);
}
