/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:44:01 by aihya             #+#    #+#             */
/*   Updated: 2019/12/22 15:52:28 by aihya            ###   ########.fr       */
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
	int		player;
	int		score;
	int		row;
	int		col;
	t_board	board;
	t_token	token;
}				t_data;

void			free_maps(t_data *data);
void			free_map(int ***map, int height);
char			*read_line();
int				read_player();
int				filler(void);
int				read_board(t_board *board);
int				init_map(int ***map, int height, int width);
int				read_header(char *target, int *height, int *width);
int				read_token(t_token *token);
int				clean_token(t_token *token);
void			print_map(int **map, int h, int w);
void			free_map(int ***map, int height);
void			heat_map(t_board *board, int player);
void			position(t_data *data);
int				star(t_token *token, int row);
int				first_one(t_token *token, int row);
int				last_one(t_token *token, int row);

#endif
