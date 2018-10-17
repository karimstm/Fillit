/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:12:04 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/17 10:43:01 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_board		*lst_addnew()
{
	t_board *board;

	board = (t_board *)malloc(sizeof(t_board));
	if (board == NULL)
		return (NULL);
	return (board);
}
