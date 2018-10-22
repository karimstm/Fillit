/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:56:14 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/22 09:08:50 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/fillit.h"

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

int     get_points(t_board **board)
{
   t_board *tmp;
   int      i;
   int      j;
   int      flag;
   int      first;
   int      counter;

   first = 0;
   counter = 0;
   flag = 0;
   tmp = *board;
   i = 0;
   while(tmp)
   {
       while (i < HEIGHT)
       {
           j = 0; 
           while (j < WIDTH)
            {
                if (tmp->shape[i][j] == 1 && flag == 0)
                {
                    flag = 1;
                    first = j;
                }
                if (tmp->shape[i][j] == 1)
                {
                    tmp->corrd[counter].x = j - first; 
                    tmp->corrd[counter].y = i;
                    printf("%d - %d\n", tmp->corrd[counter].x, tmp->corrd[counter].y);
                    counter++;
                }
                j++;
            }
            i++;
       }
       counter = 0;
       printf("=======\n");
       i = 0;
       tmp = tmp->next;
   }
   return (1);
}








