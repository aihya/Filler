/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:00:06 by aihya             #+#    #+#             */
/*   Updated: 2019/12/19 19:53:16 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set(t_data *data, int br, int bc, int *counter)
{
	int		enemy;

	enemy = data->player == 1 ? 2 : 1;
	if (data->board.map[br][bc] == enemy)
		return (0);
	if (data->board.map[br][bc] == data->player)
		(*counter)++;
	else
		data->score += data->board.map[br][bc];
	return (1);
}

int		check_column(t_data *data, int bc[2], int tc[2], int *counter)
{
	int		**map;

	map = data->token.map;
	tc[1] = 0;
	while (tc[1] < data->token.w)
	{
		if (map[tc[0]][tc[1]] == 1 && !set(data, bc[0], bc[1], counter))
			return (0);
		bc[1]++;
		tc[1]++;
	}
	return (1);
}

int		fit(t_data *data, int row, int col)
{
	int	bc[2];
	int	tc[2];
	int	counter;

	if (row + data->token.h > data->board.h
	|| col + data->token.w > data->board.w)
		return (0);
	counter = 0;
	bc[0] = row;
	tc[0] = 0;
	while (tc[0] < data->token.h)
	{
		bc[1] = col;
		if (check_column(data, bc, tc, &counter) == 0)
			return (0);
		bc[0]++;
		tc[0]++;
	}
	if (counter != 1)
		return (0);
	return (1);
}

void	set_variables(int *score, t_data *data, int row, int col)
{
	(*score) = data->score;
	data->score = 0;
	data->row = row;
	data->col = col;
}

void	position(t_data *data)
{
	int	row;
	int	col;
	int	score;

	heat_map(&(data->board), data->player);
	score = INT32_MAX;
	row = 0;
	while (row < data->board.h)
	{
		col = 0;
		while (col < data->board.w)
		{
			data->score = 0;
			if (fit(data, row, col) && data->score < score)
				set_variables(&score, data, row, col);
			col++;
		}
		row++;
	}
}
