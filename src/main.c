/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:47:34 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 22:15:12 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	ft_putstr_fd("START\n", 2);
	filler();
	ft_putstr_fd("END\n", 2);
	return (0);
}