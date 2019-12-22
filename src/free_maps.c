/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:48:33 by aihya             #+#    #+#             */
/*   Updated: 2019/12/22 15:58:33 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(int ***map, int height)
{
	int		row;

	row = 0;
	while (row < height)
	{
		if ((*map)[row] != NULL)
		{
			free((*map)[row]);
			(*map)[row] = NULL;
		}
		row++;
	}
	free((*map));
	(*map) = NULL;
}

void	free_maps(t_data *data)
{
	if (data->board.map)
		free_map(&(data->board.map), data->board.h);
	if (data->token.map)
		free_map(&(data->token.map), data->token.h);
}
