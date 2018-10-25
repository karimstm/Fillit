/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:58:46 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/25 08:42:20 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fillit.h"

t_point	init(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point	iniit(int *x, int *y)
{
	t_point point;

	point.x = *x;
	point.y = *y;
	return (point);
}

void	print_solution(char **table, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(table[i][j++]);
		}
		i++;
		ft_putchar('\n');
	}
}

int		solve_teris(t_board **board, char **table, int size, t_point *point)
{
	t_board	*tmp;
	int		x;
	int		y;

	tmp = *board;
	x = point->x;
	y = point->y;
	while (x < size)
	{
		while (y < size)
		{
			if (!(table[x][y] ^ '.'))
				if (is_safe(table, init(x, y), tmp->corrd, size))
				{
					place_teris(table, x, y, tmp);
					point->y = y;
					point->x = x;
					return (1);
				}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int		solver(t_board **board, char **table, int *counter, t_point point)
{
	t_board	*tmp;
	t_point new;

	tmp = *board;
	new.x = point.x;
	new.y = point.y;
	if (new.x == (*counter) - 1 && new.y == (*counter) - 4)
		return (0);
	if (tmp == NULL)
		return (1);
	if (solve_teris(&tmp, table, *counter, &new) == 0)
		return (0);
	if (solver(&tmp->next, table, counter, init(0, 0)) == 0)
	{
		remove_teris(table, new.x, new.y, tmp->corrd);
		if (++new.y == (*counter))
		{
			new.x++;
			new.y = 0;
		}
		return (solver(&tmp, table, counter, init(new.x, new.y)));
	}
	return (1);
}
