/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:02:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/10 04:19:40 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw(int d, t_lst data)
{
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	draw(d, data);
}

int	limits(t_lst *data, int key)
{
	if ((key == 123 || key == 0)
		&& data->map[data->y_player][data->x_player - 1] == '1')
		return (1);
	else if ((key == 124 || key == 2)
		&& data->map[data->y_player][data->x_player + 1] == '1')
		return (1);
	else if ((key == 126 || key == 13)
		&& data->map[data->y_player - 1][data->x_player] == '1')
		return (1);
	else if ((key == 125 || key == 1)
		&& data->map[data->y_player + 1][data->x_player] == '1')
		return (1);
	else
		return (0);
}
