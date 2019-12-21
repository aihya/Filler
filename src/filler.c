/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:26:16 by aihya             #+#    #+#             */
/*   Updated: 2019/12/21 16:17:33 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*read_line(void)
{
	char	*line;
	char	buff[1];
	char	buffer[1024];
	int		ret;
	int		i;

	buff[0] = '\0';
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
	(*map) = NULL;
}

int		init_map(int ***map, int height, int width)
{
	int	y;
	int	x;

	if (((*map) = (int **)malloc(sizeof(int *) * height)) == NULL)
		return (0);
	y = 0;
	while (y < height)
	{
		if (((*map)[y] = (int *)malloc(sizeof(int) * width)) == NULL)
		{
			free_map(map, height);
			return (0);
		}
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

int		error(t_data *data, int target)
{
	if (target == 1)
	{
		ft_putendl_fd("Board Error", 2);
		free_map(&(data->board.map), data->board.h);
	}
	else
	{
		ft_putendl_fd("Token Error", 2);
		free_map(&(data->token.map), data->token.h);
	}
	return (0);
}

int		filler(void)
{
	t_data	data;

	data.player = 0;
	if ((data.player = read_player()) == 0)
		return (0);
	data.board.map = NULL;
	data.token.map = NULL;
	while (1337)
	{
		if (read_board(&(data.board)) == 0)
			return (error(&data, 1));
		if (read_token(&(data.token)) == 0)
			return (error(&data, 2));
		data.row = 0;
		data.col = 0;
		position(&data);
		ft_putnbr_fd(data.row - data.token.r_offset, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(data.col - data.token.c_offset, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	if (data.board.map)
		free_map(&(data.board.map), data.board.h);
	if (data.token.map)
		free_map(&(data.token.map), data.token.h);
	return (1);
}
