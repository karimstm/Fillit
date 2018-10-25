/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:12:04 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/25 08:54:50 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		*lst_addnew(void)
{
	t_board *board;

	board = (t_board *)malloc(sizeof(t_board));
	if (board == NULL)
		return (NULL);
	return (board);
}
