/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:40:48 by aihya             #+#    #+#             */
/*   Updated: 2019/12/21 15:11:11 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	free_return(char ***buffer, char **line)
{
	ft_chain_free(buffer);
	ft_strdel(line);
	return (0);
}

int			read_header(char *target, int *height, int *width)
{
	char	*line;
	char	**buffer;

	line = NULL;
	if ((line = read_line()) == NULL)
		return (0);
	buffer = ft_strsplit_del(line, ":");
	if (ft_chain_size(buffer) != 1)
		return (free_return(&buffer, &line));
	ft_strdel(&line);
	line = ft_strdup(buffer[0]);
	ft_chain_free(&buffer);
	buffer = ft_strsplit_del(line, " ");
	if (ft_chain_size(buffer) != 3 || !ft_strequ(buffer[0], target)
	|| !ft_strisnum(buffer[1]) || !ft_strisnum(buffer[2]))
		return (free_return(&buffer, &line));
	(*height) = ft_atoi(buffer[1]);
	(*width) = ft_atoi(buffer[2]);
	ft_strdel(&line);
	ft_chain_free(&buffer);
	if ((*height) == 0 || (*width) == 0)
		return (0);
	return (1);
}
