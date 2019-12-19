/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:53:48 by aihya             #+#    #+#             */
/*   Updated: 2019/12/19 16:59:41 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	read_useless_line()
{
	char	*line;

	line = read_line();
	if (line != NULL)
		ft_strdel(&line);
}

static int	set_map_col(char ***buffer, t_board *board, int row, int col)
{
	if (ft_strchr(".oOxX", (*buffer)[1][col]) == NULL)
	{
		ft_chain_free(buffer);
		return (0);
	}
	else if ((*buffer)[1][col] == '.')
		board->map[row][col] = 0;
	else if ((*buffer)[1][col] == 'o' || (*buffer)[1][col] == 'O')
		board->map[row][col] = 1;
	else if ((*buffer)[1][col] == 'x' || (*buffer)[1][col] == 'X')
		board->map[row][col] = 2;
	return (1);
}

static int	read_row(t_board *board, int row)
{
	char	*line;
	char	**buffer;
	int		col;

	line = NULL;
	if ((line = read_line()) == NULL)
	{
		//dprintf(2, "Read_line error\n");
		return (0);
	}
	buffer = ft_strsplit_del(line, " ");
	ft_strdel(&line);
	if (ft_chain_size(buffer) != 2)
	{
		//dprintf(2, "buffer size error: %zu\n", ft_chain_size(buffer));
		ft_chain_free(&buffer);
		return (0);
	}
	if (ft_strlen(buffer[1]) != board->w)
	{
		//dprintf(2, "lenght error: %zu\n", ft_strlen(buffer[1]));
		ft_chain_free(&buffer);
		return (0);
	}
	col = 0;
	while (col < board->w)
	{
		if (set_map_col(&buffer, board, row, col) == 0)
		{
			//dprintf(2, "set_map_col error\n");
			return (0);
		}
		col++;
	}
	ft_chain_free(&buffer);
	return (1);
}

int			read_board(t_board *board)
{
	int		height;
	int		width;
	int		row;

	height = 0;
	width = 0;
	if (!read_header("Plateau", &height, &width))
	{
		//dprintf(2, "read_header error\n");
		return (0);
	}
	board->h = height;
	board->w = width;
	read_useless_line();
	if (board->map != NULL)
		free_map(&(board->map), board->h, board->w);
	if (init_map(&(board->map), board->h, board->w) == 0)
	{
		//dprintf(2, "Cannot init map\n");
		return (0);
	}
	row = 0;
	while (row < height)
	{
		if (read_row(board, row) == 0)
		{
			//dprintf(2, "read_row error\n");
			return (0);
		}
		row++;
	}
	return (1);
}