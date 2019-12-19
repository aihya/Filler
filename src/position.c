/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:00:06 by aihya             #+#    #+#             */
/*   Updated: 2019/12/19 17:03:17 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	fit(t_data *data, int row, int col, int enemy)
{
	int	br;
	int	bc;
	int	tr;
	int	tc;
	int	counter;


	
//	dprintf(2, "Test: %d %d\n", row, col);
	if (row + data->token.h > data->board.h)
		return (0);
	if (col + data->token.w > data->board.w)
		return (0);
	counter = 0;
	br = row;
	tr = 0;
	
	while (tr < data->token.h)
	{
		bc = col;
		tc = 0;
		while (tc < data->token.w)
		{
			if (data->token.map[tr][tc] == 1)
			{
				if (data->board.map[br][bc] == enemy)
					return (0);
				if (data->board.map[br][bc] == data->player)
					counter++;
				else
					data->score += data->board.map[br][bc];
			}
			bc++;
			tc++;
		}
		br++;
		tr++;
	}
	if (counter != 1)
		return (0);
	return (1);
}

void	position(t_data *data)
{
	int	row;
	int	col;
	int	score;
	int	enemy;

	heat_map(&(data->board), data->player);
//	print_map(data->board.map, data->board.h, data->board.w);
	score = INT32_MAX;
	enemy = data->player == 1 ? 2 : 1;
	row = 0;
	while (row < data->board.h)
	{
		col = 0;
		while (col < data->board.w)
		{
			data->score = 0;
			if (fit(data, row, col, enemy))
			{
				if (data->score < score)
				{
			//		dprintf(2, "\tScore: %d\n", data->score);
					score = data->score;
					data->score = 0;
					data->row = row;
					data->col = col;
				}
			}
			col++;
		}
		row++;
	}
}