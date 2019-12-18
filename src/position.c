/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:00:06 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 19:54:26 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		position(t_board *board, t_token *token, int player)
{
	int		outer_layer;

	outer_layer = heat_map(board, player);
	dprintf(2, "Outer Layer: %d\n", outer_layer);
	
	
	
	return (1);
}