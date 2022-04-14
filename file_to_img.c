/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:18:08 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/10 23:27:06 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player(int x, int y, t_lst *data)
{
	data->player_u.path = "images/player_u.xpm";
	data->player_u.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player_u.path, &x, &y);
	data->player_d.path = "images/player_d.xpm";
	data->player_d.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player_d.path, &x, &y);
	data->player_l.path = "images/player_l.xpm";
	data->player_l.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player_l.path, &x, &y);
	data->player_r.path = "images/player_r.xpm";
	data->player_r.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player_r.path, &x, &y);
}

void	file_to_img(t_lst *data)
{
	int	x;
	int	y;

	x = PIXEL;
	y = PIXEL;
	data->wall.path = "images/wall.xpm";
	data->wall.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->wall.path, &x, &y);
	data->collect.path = "images/collectible.xpm";
	data->collect.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->collect.path, &x, &y);
	data->exit.path = "images/exit.xpm";
	data->exit.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->exit.path, &x, &y);
	data->backg.path = "images/empty_space.xpm";
	data->backg.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->backg.path, &x, &y);
	player(x, y, data);
}
