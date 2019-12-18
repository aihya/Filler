/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:40:48 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 18:18:14 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_header(char *target, int *height, int *width)
{
	char	*line;
	char	**buffer_1;

	line = NULL;
	if ((line = read_line()) == NULL)
		return (0);
	ft_putendl_fd(line, 2);
	buffer_1 = ft_strsplit_del(line, ":");
	if (ft_chain_size(buffer_1) != 1)
	{
		ft_chain_free(&buffer_1);
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	line = ft_strdup(buffer_1[0]);
	ft_chain_free(&buffer_1);
	buffer_1 = ft_strsplit_del(line, " ");
	if (ft_chain_size(buffer_1) != 3	|| !ft_strequ(buffer_1[0], target)
	||	!ft_strisnum(buffer_1[1])		|| !ft_strisnum(buffer_1[2]))
	{
		ft_chain_free(&buffer_1);
		ft_strdel(&line);
		return (0);
	}
	(*height) = ft_atoi(buffer_1[1]);
	(*width) = ft_atoi(buffer_1[2]);
	if ((*height) == 0 || (*width) == 0)
		return 0;
	return (1);
}