/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:58:46 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/22 11:48:12 by amoutik          ###   ########.fr       */
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
     return (table);
}

int		is_safe(char **table, int i, int j, t_point corr[4])
{
	int pos = 0;
	while (pos < 4)
	{
		if (i + corr[pos].y >= 4 || j + corr[pos].x >= 4)
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

void	print_solution(char **table)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c \t", table[i][j++]); 
		}
		i++;
		printf("\n");
	}
}

int     solver(t_board **board, char **table, int *counter)
{
    int i;
    int j;
	t_board *tmp;

	*counter = (int)sqrt((*counter) * 4);
    table = initial_table(*counter);
	tmp = *board;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (table[i][j] == '.')
				if(is_safe(table, i, j, tmp->corrd))
				{
					place_teris(table, i, j, tmp->corrd, tmp->c);
					if (tmp->next)
						tmp = tmp->next;
				}
			j++;
		}
		i++;
	}
	print_solution(table);
    return (0);
}
