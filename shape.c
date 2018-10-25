/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:56:14 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/25 09:07:10 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	block_v(int block[4][4], int min_i, int min_j)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (block[i][j] == 1)
			{
				block[i][j] = 0;
				block[i - min_j][j - min_i] = 1;
			}
			j++;
		}
		i++;
	}
}

void	init_reform(int *flag, int *i, int *min_i, int *min_j)
{
	*flag = 0;
	*i = 0;
	*min_i = 4;
	*min_j = 0;
}

int		reform_shape_center(int block[4][4])
{
	int i;
	int j;
	int min_i;
	int min_j;
	int flag;

	init_reform(&flag, &i, &min_i, &min_j);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (block[i][j] == 1)
			{
				if (!flag && (flag = 1))
					min_j = i;
				if (j < min_i)
					min_i = j;
			}
			j++;
		}
		i++;
	}
	block_v(block, min_i, min_j);
	return (0);
}

void	init_intern(int *flag, int *first, int *j)
{
	*flag = 1;
	*first = *j;
}

void	get_points(t_board **board, int i, int j, int flag)
{
	t_board *tmp;
	int		first;
	int		counter;

	init_get_point(&flag, &i, &first, &counter);
	tmp = *board;
	while (tmp)
	{
		while (++i < HEIGHT)
		{
			j = -1;
			while (++j < WIDTH)
			{
				if (tmp->shape[i][j] == 1 && flag == 0)
					init_intern(&flag, &first, &j);
				if (tmp->shape[i][j] == 1)
				{
					tmp->corrd[counter].x = j - first;
					tmp->corrd[counter++].y = i;
				}
			}
		}
		init_get_point(&flag, &i, &first, &counter);
		tmp = tmp->next;
	}
}
