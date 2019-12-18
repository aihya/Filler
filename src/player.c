/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:31:01 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 17:07:27 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	read_player()
{
	int		player;
	char	*line;

	player = 0;
	line = NULL;
	if ((line = read_line()) == NULL)
		return (0);
	ft_putendl_fd(line, 2);
	if (ft_strstr(line, "$$$ exec p1 :") == NULL
	&&	ft_strstr(line, "$$$ exec p2 :") == NULL)
	{
		if (line != NULL)
			ft_strdel(&line);
		return (0);
	}
	player = ft_strchr(line, '1') != NULL ? 1 : 2;
	ft_strdel(&line);
	return (player);
}