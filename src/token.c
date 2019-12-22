/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:32:53 by aihya             #+#    #+#             */
/*   Updated: 2019/12/22 15:52:33 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	set_map_col(char **line, t_token *token, int row, int col)
{
	if (ft_strchr(".*", (*line)[col]) == NULL)
	{
		ft_strdel(line);
		return (0);
	}
	else if ((*line)[col] == '.')
		token->map[row][col] = 0;
	else if ((*line)[col] == '*')
		token->map[row][col] = 1;
	return (1);
}

static int	read_row(t_token *token, int row)
{
	char	*line;
	int		col;

	line = NULL;
	if ((line = read_line()) == NULL)
		return (0);
	if ((int)ft_strlen(line) != token->w)
	{
		ft_strdel(&line);
		return (0);
	}
	col = 0;
	while (col < token->w)
	{
		if (set_map_col(&line, token, row, col) == 0)
			return (0);
		col++;
	}
	ft_strdel(&line);
	return (1);
}

int			read_token(t_token *token)
{
	int	height;
	int	width;
	int	row;

	height = 0;
	width = 0;
	if (!read_header("Piece", &height, &width))
		return (0);
	if (token->map != NULL)
		free_map(&(token->map), token->h);
	token->h = height;
	token->w = width;
	if (init_map(&(token->map), token->h, token->w) == 0)
		return (0);
	row = 0;
	while (row < height)
	{
		if (read_row(token, row) == 0)
			return (0);
		row++;
	}
	if (clean_token(token) == 0)
		return (0);
	return (1);
}
