/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:24:38 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/15 00:30:51 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	backspace(int a, int b, t_lst data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.backg.ptr, (a * PIXEL), (b * PIXEL));
}

static void	player_view(t_lst data, int a, int b, int d)
{
	if (d == 1)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.player_u.ptr, (a * PIXEL), (b * PIXEL));
	else if (d == 2)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.player_d.ptr, (a * PIXEL), (b * PIXEL));
	else if (d == 3)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.player_l.ptr, (a * PIXEL), (b * PIXEL));
	else if (d == 4)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.player_r.ptr, (a * PIXEL), (b * PIXEL));
}

static void	whiled(int d, int a, int b, t_lst data)
{
	if (data.map[b][a] == '1')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.wall.ptr, (a * PIXEL), (b * PIXEL));
	else if (data.map[b][a] == '0')
		backspace(a, b, data);
	else if (data.map[b][a] == 'C')
	{
		backspace(a, b, data);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.collect.ptr, (a * PIXEL), (b * PIXEL));
	}
	else if (data.map[b][a] == 'E')
	{
		backspace(a, b, data);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.exit.ptr, (a * PIXEL), (b * PIXEL));
	}
	else if (data.map[b][a] == 'P')
	{
		backspace(a, b, data);
		player_view(data, a, b, d);
	}
}

void	draw(int d, t_lst	data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (b < data.h)
	{
		a = 0;
		while (a < data.w)
		{
			whiled(d, a, b, data);
			a++;
		}
	b++;
	}
}
