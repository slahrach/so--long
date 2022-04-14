/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:40:54 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/11 22:06:53 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# define PIXEL 64

typedef struct s_vars
{
	int	e;
	int	p;
	int	h;
	int	w;
}	t_vars;

typedef struct s_img
{
	void	*ptr;
	char	*path;
}	t_img;

typedef struct s_lst
{
	char	*filename;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
	int		x_player;
	int		y_player;
	int		c;
	int		moves;
	t_img	wall;
	t_img	backg;
	t_img	collect;
	t_img	player_u;
	t_img	player_d;
	t_img	player_l;
	t_img	player_r;
	t_img	exit;
}	t_lst;

int			move(int key, t_lst *data);
char		*read_map(t_lst data);
void		check_args(t_lst data);
void		check_map(t_lst *data);
void		check_medlines(t_lst data);
void		check_firstlast(t_lst data);
void		file_to_img(t_lst *data);
void		invalid_map(int a);
void		invalid_args(int a);
void		draw(int d, t_lst	data);
void		redraw(int d, t_lst data);
int			limits(t_lst *data, int key);
int			free_exit(t_lst *data);
void		congrats(t_lst *data);
void		movements(t_lst *data);

#endif