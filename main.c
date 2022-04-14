/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:34:55 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/15 00:31:15 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_firstlast(t_lst	data)
{
	int	w;

	w = 0;
	while (data.map[0][w] != '\0')
	{
		if (data.map[0][w] != '1')
			invalid_map(2);
		w++;
	}
	w = 0;
	while (data.map[data.h - 1][w] != '\0')
	{
		if (data.map[data.h - 1][w] != '1')
			invalid_map(2);
		w++;
	}
}

void	check_medlines(t_lst data)
{
	int	h;

	h = 1;
	while (h < (data.h - 1))
	{
		if (data.map[h][0] != '1')
			invalid_map(2);
		h++;
	}
	while (--h > 0)
	{
		if (data.map[h][data.w - 1] != '1')
			invalid_map(2);
	}
}

int	main(int argc, char **argv)
{
	t_lst	data;
	char	*store;

	if (argc != 2)
		invalid_args(1);
	data.filename = argv[1];
	check_args(data);
	store = read_map(data);
	if (store[0] == '\0' || store == NULL)
		invalid_map(1);
	data.map = ft_split(store, '\n');
	free(store);
	check_map(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.w * PIXEL),
			(data.h * PIXEL), "BABY'S GAME");
	data.moves = 0;
	file_to_img(&data);
	draw(1, data);
	mlx_hook(data.win_ptr, 17, 0L, free_exit, &data);
	mlx_key_hook(data.win_ptr, move, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
