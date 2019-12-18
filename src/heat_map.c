/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:21:58 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 20:00:10 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fill_columns(t_board *board, int row, int col, int layer)
{
	int		entry;

	entry = 0;
	if (col - 1 >= 0 && board->map[row][col - 1] == 0 && (entry = 1))
		board->map[row][col - 1] = layer;
	if (col + 1 < board->w && board->map[row][col + 1] == 0 && (entry = 1))
		board->map[row][col + 1] = layer;
	if (board->map[row][col] == 0 && (entry = 1))
		board->map[row][col] = layer;
	return (entry);
}

static int	surround_target(t_board *board, int row, int col, int layer)
{
	int		entry;
	int		res;

	res = 0;
	entry = 0;
	if (row - 1 >= 0)
		entry = fill_columns(board, row - 1, col, layer);
	res = entry == 1 && res == 0 ? 1 : res;
	if (row + 1 < board->h)
		entry = fill_columns(board, row + 1, col, layer);
	res = entry == 1 && res == 0 ? 1 : res;
	if (col - 1 >= 0 && board->map[row][col - 1] == 0 && (entry = 1))
		board->map[row][col - 1] = layer;
	res = entry == 1 && res == 0 ? 1 : res;
	if (col + 1 < board->w && board->map[row][col + 1] == 0 && (entry = 1))
		board->map[row][col + 1] = layer;
	res = entry == 1 && res == 0 ? 1 : res;
	return (res);
}

static int	superpose(t_board *board, int target, int layer)
{
	int		row;
	int		col;
	int		entry;
	int		res;

	entry = 0;
	res = 0;
	row = 0;
	while (row < board->h)
	{
		col = 0;
		while (col < board->w)
		{
			if (board->map[row][col] == target)
			{
				entry = surround_target(board, row, col, layer);
				res = entry == 1 ? 1 : res;
			}
			col++;
		}
		row++;
	}
	return (res);
}

int			heat_map(t_board *board, int player)
{
	int		target;
	int		layer;

	target = player == 1 ? 2 : 1;
	layer = 3;
	while (superpose(board, target, layer))
	{
		target = layer;
		layer++;
	}
	return (target);
}