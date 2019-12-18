/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:44:01 by aihya             #+#    #+#             */
/*   Updated: 2019/12/18 19:51:09 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_board
{
	int		h;
	int		w;
	int		**map;
}				t_board;

typedef struct	s_token
{
	int		r_offset;
	int		c_offset;
	int		h;
	int		w;
	int		**map;
}				t_token;

typedef struct	s_data
{
	t_board	*board;
	t_token	*token;
	int		player;
}				t_data;

char	*read_line();
int		read_player();
void	filler();
int		read_board(t_board *board);
int		init_map(int ***map, int height, int width);
int		read_header(char *target, int *height, int *width);
int		read_token(t_token *token);
int		clean_token(t_token *token);
void	print_map(int **map, int h, int w);
void	free_map(int ***map, int height, int width);
int		heat_map(t_board *board, int player);
int		position(t_board *board, t_token *token, int player);

#endif
