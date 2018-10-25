/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 08:41:31 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/25 09:02:30 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define HEIGHT 4
# define WIDTH 4
# define BLOCK '#'
# define EMPTY '.'
# include "libft.h"
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"

typedef struct		s_point
{
	int x;
	int y;
}					t_point;

typedef	struct		s_board
{
	int				shape[4][4];
	char			c;
	t_point			corrd[4];
	struct s_board	*next;
}					t_board;

t_board				*lst_addnew();
int					reform_shape_center(int block[4][4]);
void				get_points(t_board **board, int i, int j, int flag);
int					solver(t_board **brd, char **t, int *ctr, t_point pt);
void				place_teris(char **table, int i, int j, t_board *brd);
int					is_safe(char **t, t_point ptn, t_point corr[4], int size);
char				**initial_table(int size);
t_board				*test(t_board *board, int *counter, char c);
void				to_zero(int *nheight, int *nshape);
void				initial(int *i, char *c);
int					open_file(char *file);
void				init_get_point(int *flag, int *i, int *first, int *counter);
void				remove_teris(char **table, int x, int y, t_point tmp[4]);
void				print_solution(char **table, int size);
int					is_valid(int shape[4][4]);
t_point				init(int i, int c);

#endif
