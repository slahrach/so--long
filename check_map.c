/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:52:51 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/09 21:47:18 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	whiled2(t_lst *data, t_vars *var)
{
	if (data->map[var->h][var->w] == '1'
				|| data->map[var->h][var->w] == '0'
				|| data->map[var->h][var->w] == 'E'
				|| data->map[var->h][var->w] == 'P'
				|| data->map[var->h][var->w] == 'C')
	{
		if (data->map[var->h][var->w] == 'E')
			var->e += 1;
		else if (data->map[var->h][var->w] == 'P')
		{
			data->x_player = var->w;
			data->y_player = var->h;
			var->p += 1;
		}
		else if (data->map[var->h][var->w] == 'C')
			data->c++;
	}
	else
		invalid_map(3);
}

static	void	verify_char(t_lst *data, t_vars *var)
{
	while (var->h < data->h)
	{
		var->w = 0;
		while (var->w < data->w)
		{
			whiled2(data, var);
			var->w++;
		}
		var->h++;
	}
}

static void	check_symbols(t_lst *data)
{
	t_vars	var;

	var.h = 0;
	var.e = 0;
	var.p = 0;
	var.w = 0;
	data->c = 0;
	verify_char(data, &var);
	if (var.e < 1 || var.p != 1 || data->c < 1)
		invalid_map(4);
	else
		return ;
}

void	check_map(t_lst *data)
{
	int		h;
	int		a;

	a = 1;
	h = 0;
	data->w = (int) ft_strlen(data->map[0]);
	while (data->map[h] != NULL)
		h++;
	data->h = h;
	while (a < h)
	{
		if (data->w != (int) ft_strlen(data->map[a]))
			invalid_map(1);
		a++;
	}
	check_firstlast(*data);
	check_medlines(*data);
	check_symbols(data);
}
