/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdiab- <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:21:36 by zdiab-            #+#    #+#             */
/*   Updated: 2018/10/25 09:06:56 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <math.h>

void		initial(int *i, char *c)
{
	*i = -1;
	*c = 'A';
}

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

void		to_zero(int *nheight, int *nshape)
{
	*nheight = 0;
	*nshape = 0;
}
