/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:00:58 by aihya             #+#    #+#             */
/*   Updated: 2019/12/19 19:01:23 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		star(t_token *token, int row)
{
	int	col;

	col = 0;
	while (col < token->w)
	{
		if (token->map[row][col] == 1)
			return (1);
		col++;
	}
	return (0);
}

int		first_one(t_token *token, int row)
{
	int	col;

	col = 0;
	while (col < token->w)
	{
		if (token->map[row][col] == 1)
			return (col);
		col++;
	}
	return (-1);
}

int		last_one(t_token *token, int row)
{
	int	col;

	col = token->w - 1;
	while (col >= 0)
	{
		if (token->map[row][col] == 1)
			break ;
		col--;
	}
	return (col);
}
