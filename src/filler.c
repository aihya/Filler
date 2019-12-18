/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:26:16 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 19:53:15 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*read_line()
{
	char	*line;
	char	buffer[1];
	int		ret;

	line = NULL;
	ret = 0;
	while ((ret = read(STDIN_FILENO, buffer, 1)) != -1)
	{
		if (ft_strchr(buffer, '\n') || ret == 0)
			break ;
		ft_strappend(&line, buffer[0], 1);
		ret = 0;
	}
	return (line);
}

void	free_map(int ***map, int height, int width)
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
	(*map) = NULL;
}

int		init_map(int ***map, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	if (((*map) = (int **)malloc(sizeof(int *) * height)) == NULL)
		return (0);
	while (y < height)
	{
		if (((*map)[y] = (int *)malloc(sizeof(int) * width)) == NULL)
			return (0);
		x = 0;
		while (x < width)
		{
			(*map)[y][x] = 0;
			x++;
		}
		y++;
	}
	return (1);
}

void	print_map(int **map, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			ft_putchar_fd(map[i][j] + 48, 2);
			j++;
		}
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	filler()
{
	int		player;
	t_board	board;
	t_token	token;

	player = 0;
	if ((player = read_player()) == 0)
		return ;
	board.map = NULL;
	token.map = NULL;
	token.r_offset = 0;
	token.c_offset = 0;
	while (1337)
	{
		ft_putendl_fd("Board:", 2);
		if (read_board(&board) == 0)
		{
			ft_putendl_fd("Board Error", 2);
			free_map(&(board.map), board.h, board.w);
			return ;
		}
		ft_putendl_fd("Token", 2);
		if (read_token(&token) == 0)
		{
			free_map(&(token.map), token.h, token.w);
			ft_putendl_fd("Token Error", 2);
			return ;
		}
		print_map(token.map, token.h, token.w);
		ft_putendl_fd("Heat Map:", 2);
		position(&board, &token, player);
		print_map(board.map, board.h, board.w);
		ft_putstr_fd("8 1\n", STDOUT_FILENO);
	}
}