/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 08:41:31 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/19 18:22:13 by amoutik          ###   ########.fr       */
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

typedef struct 		s_board
{
	int				shape[4][4];
	char			c;
	struct s_board	*next;
}					t_board;

t_board				*lst_addnew();
int					reform_shape_center(int block[4][4]);
#endif
