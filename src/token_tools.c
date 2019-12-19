/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:18:45 by aihya             #+#    #+#             */
/*   Updated: 2019/12/19 16:11:28 by aihya            ###   ########.fr       */
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

void	set_offsets(t_token *token)
{
	int	row;
	int	col;
	int	min;

	token->r_offset = 0;
	token->c_offset = 0;
	row = 0;
	while (row < token->h)
	{
		if ((col = first_one(token, row)) >= 0)
			break ;
		row++;
	}
	token->r_offset = row == token->h ? 0 : row;
	row = 0;
	min = token->w;
	while (row < token->h)
	{
		col = first_one(token, row);
		if (col >= 0 && col < min)
			min = col;
		row++;
	}
	token->c_offset = min < token->w ? min : token->c_offset;
}

void	set_token_dimentions(t_token *token, int *new_h, int *new_w)
{
	int	row;
	int	pos;

	row = 0;
	
	while (row < token->h)
	{
		(*new_h) = star(token, row) ? (*new_h) + 1 : (*new_h);
		if (token->w > 0)
		{
			if ((pos = last_one(token, row)) >= 0)
				(*new_w) = (*new_w) < pos + 1 ? pos + 1 : (*new_w);
		}	
		row++;
	}
	(*new_w) -= token->c_offset;
}

int		trim_offsets(t_token *token, int new_h, int new_w)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	**map;

	if ((map = (int **)malloc(sizeof(int *) * new_h)) == NULL)
		return (0);
	i = 0;
	r = token->r_offset;
	while (r < new_h + token->r_offset)
	{
		if ((map[i] = (int *)malloc(sizeof(int) * new_w)) == NULL)
			return (0);
		j = 0;
		c = token->c_offset;
		while (c < new_w + token->c_offset)
		{
			map[i][j] = token->map[r][c];
			j++;
			c++;
		}
		i++;
		r++;
	}
	free_map(&(token->map), token->h, token->w);
	token->map = map;
	return (1);
}

int		clean_token(t_token *token)
{
	int	new_height;
	int	new_width;

	token->c_offset = 0;
	token->r_offset = 0;	
	set_offsets(token);
	new_height = 0;
	new_width = 0;
	set_token_dimentions(token, &new_height, &new_width);
//	dprintf(2, "Offsets: %d, %d\n", token->r_offset, token->c_offset);
//	dprintf(2, "Dimensions: %d, %d\n", new_height, new_width);
	if (trim_offsets(token, new_height, new_width) == 0)
		return (0);
	token->h = new_height;
	token->w = new_width;
	return (1);
}