/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:56:14 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/20 15:12:28 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void 	print_shape(int block[4][4])
{
	int i;
	int j;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			printf("%d\t", block[i][j++]);
		printf("\n");
		i++;
	}
	printf("\n");
}

int check_term()
{
	return (1);
}

int verif(int shape[4][4], int block[4][4], int k, int l)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		if (k == 3)
		{k = 0; l++;}
		j = 0;
		while (j + k < 4)
		{
			if(shape[l][j + k] == block[i][j] && shape[l][j + k] == 1 && l == 4)
				return (0);
			if(shape[l][j + k] == block[i][j] && shape[l][j + k] == 1)
				return(verif(shape, block, ++k, l));
			j++;
		}
		i++;
	}
	return (1);
}

int		my_verification(int shape[4][4], int block[4][4], int k)
{
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	if (k == 3)
	{	k = 0;}
	while (i < 4)
	{
		j = 0;
		while (j + k < 4)
		{
			if (shape[i][j + k] == block[l][j]  && shape[i][j + k] == 1)
				return (my_verification(shape, block, ++k));
			j++;
		}
		i++;
		if (j == 4)
			l++;
		k = 0;
	}
	return (0);
}

int		main()
{
	int i;
	int j;
	int min_i;
	int min_j;
	int flag = 0;
	int x;
	int y;

	i = 0;
	min_i = 4;
	min_j = 0;
	int shape[4][4] = 
	{
		{1, 1, 1, 1},
		{1, 1, 1, 0},
		{1, 1, 0, 0},
		{0, 1, 1, 0}
	};
	int block[4][4] = 
	{
		{1, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 0}
	};

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

	i = 0;
	j = 0;
	int is_safe = 0;
	int k, o;
	k = 0;
	o = 0;

	if (verif(shape, block, k, o) == 1)
		printf("ok!!\n");
	else
		printf(" not ok!!\n");


	print_shape(shape);
	printf("min_i -> %d\n", min_i);	
	printf("min_j -> %d\n", min_j);	
	return(0);
}
