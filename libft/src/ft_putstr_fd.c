/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:00:31 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 16:20:16 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char const *c, int fd)
{
	unsigned int	i;

	if (c)
	{
		i = 0;
		while (c[i])
		{
			write(fd, &c[i], 1);
			i++;
		}
	}
}
