/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:26:16 by aihya             #+#    #+#             */
/*   Updated: 2019/12/19 17:57:58 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*read_line()
{
	char	*line;
	char	buff[1];
	char	buffer[1024];
	int		ret;
	int		i;

	line = NULL;
	ret = 0;
	i = 0;
	while ((ret = read(STDIN_FILENO, buff, 1)) != -1 && i < 1023)
	{
		if (ft_strchr(buff, '\n') || ret == 0)
			break ;
		buffer[i] = buff[0];
		ret = 0;
		i++;
	}
	buffer[i] = 0;
	line = ft_strdup(buffer);
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
			if (map[i][j] == 0)
				ft_putchar_fd('.', 2);
			else
				ft_putchar_fd(map[i][j] + 48, 2);
			j++;
		}
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	filler()
{
	t_data	data;
	// t_board	board;
	// t_token	token;

	data.player = 0;
	if ((data.player = read_player()) == 0)
		return ;
	data.board.map = NULL;
	data.token.map = NULL;
	// data.board = NULL;
	// data.token = NULL;
	
	while (1337)
	{
		if (read_board(&(data.board)) == 0)
		{
			ft_putendl_fd("Board Error", 2);
			free_map(&(data.board.map), data.board.h, data.board.w);
			return ;
		}
//		ft_putendl_fd("Board", 2);
//		print_map(data.board.map, data.board.h, data.board.w);
		if (read_token(&(data.token)) == 0)
		{
			free_map(&(data.token.map), data.token.h, data.token.w);
			ft_putendl_fd("Token Error", 2);
			return ;
		}
//		ft_putendl_fd("Token", 2);
//		print_map(data.token.map, data.token.h, data.token.w);
		data.row = 0;
		data.col = 0;
//		ft_putendl_fd("+++++++++", 2);
		position(&data);
	//	dprintf(2, "%d %d\n", data.row - data.token.r_offset, data.col - data.token.c_offset);
		ft_putnbr_fd(data.row - data.token.r_offset, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(data.col - data.token.c_offset, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	//	ft_putendl_fd("8 1", STDOUT_FILENO);
	}
}