/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 08:41:31 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/22 11:28:01 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define HEIGHT 4
# define WIDTH 4
# define BLOCK '#'
# define EMPTY '.'

# include "libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct      s_point
{
    int x;
    int y;
}                   t_point;

typedef struct 		s_board
{
	int				shape[4][4];
	char			c;
    t_point         corrd[4];
	struct s_board	*next;
}					t_board;

t_board				*lst_addnew();
int					reform_shape_center(int block[4][4]);
int                 get_points(t_board **board);
int 				solver(t_board **board, char **table, int *counter);
void				place_teris(char **table, int i, int j, t_point corr[4], char c);
int					is_safe(char **table, int i, int j, t_point corr[4]);
char					**initial_table(int size);

#endif
