/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:56:14 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/19 16:27:59 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		reform_shape_center(int block[4][4])
{
	int i;
	int j;
	int min_i;
	int min_j;
	int flag = 0;

	i = 0;
	min_i = 4;
	min_j = 0;
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
	printf("min_i -> %d\n", min_i);	
	printf("min_j -> %d\n", min_j);	
	return(0);
}
