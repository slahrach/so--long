/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:54:44 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/11 22:08:17 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(int key, t_lst *data)
{
	if ((key == 123 || key == 0) && limits(data, key) == 0)
	{
		if (data->map[data->y_player][data->x_player - 1] == 'C')
			data->c--;
		else if (data->map[data->y_player][data->x_player - 1] == 'E')
		{
			if (data->c == 0)
				congrats(data);
			else
				return ;
		}
		data->x_player--;
		data->map[data->y_player][data->x_player + 1] = '0';
		data->map[data->y_player][data->x_player] = 'P';
		redraw(3, *data);
		movements(data);
	}
}

static void	move_right(int key, t_lst *data)
{
	if ((key == 124 || key == 2) && limits(data, key) == 0)
	{
		if (data->map[data->y_player][data->x_player + 1] == 'C')
			data->c--;
		else if (data->map[data->y_player][data->x_player + 1] == 'E')
		{
			if (data->c == 0)
				congrats(data);
			else
				return ;
		}
		data->x_player++;
		data->map[data->y_player][data->x_player - 1] = '0';
		data->map[data->y_player][data->x_player] = 'P';
		redraw(4, *data);
		movements(data);
	}
}

static void	move_down(int key, t_lst *data)
{
	if ((key == 125 || key == 1) && limits(data, key) == 0)
	{
		if (data->map[data->y_player + 1][data->x_player] == 'C')
			data->c--;
		else if (data->map[data->y_player + 1][data->x_player] == 'E')
		{
			if (data->c == 0)
				congrats(data);
			else
				return ;
		}
		data->y_player++;
		data->map[data->y_player - 1][data->x_player] = '0';
		data->map[data->y_player][data->x_player] = 'P';
		redraw(2, *data);
		movements(data);
	}
}

static void	move_up(int key, t_lst *data)
{
	if ((key == 126 || key == 13) && limits(data, key) == 0)
	{
		if (data->map[data->y_player - 1][data->x_player] == 'C')
			data->c--;
		else if (data->map[data->y_player - 1][data->x_player] == 'E')
		{
			if (data->c == 0)
				congrats(data);
			else
				return ;
		}
		data->y_player--;
		data->map[data->y_player + 1][data->x_player] = '0';
		data->map[data->y_player][data->x_player] = 'P';
		redraw(1, *data);
		movements(data);
	}
}

int	move(int key, t_lst *data)
{
	if (key == 53)
		free_exit(data);
	move_left (key, data);
	move_right (key, data);
	move_down (key, data);
	move_up (key, data);
	return (key);
}
