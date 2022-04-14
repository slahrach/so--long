/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:14:20 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/15 16:43:29 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(int a)
{
	ft_putstr_fd("Error : \n", 1);
	if (a == 1)
		ft_putstr_fd("The Map Must be Rectangular\n", 1);
	else if (a == 2)
		ft_putstr_fd("The Map Is Not Surrounded By Walls\n", 1);
	else if (a == 3)
		ft_putstr_fd("Unkown Character In The Map\n", 1);
	else if (a == 4)
		ft_putstr_fd("Map Elements Are More Or Less Than Required\n", 1);
	exit(1);
}

void	invalid_args(int a)
{
	ft_putstr_fd("Error : \n", 1);
	if (a == 1)
		ft_putstr_fd("The Number of Arguments Is Invalid\n", 1);
	else if (a == 2)
		ft_putstr_fd("the extension of the map file must be '.ber' \n", 1);
	if (a == 3)
		perror("Opening file failed");
	exit(1);
}

int	free_exit(t_lst *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}

void	congrats(t_lst *data)
{
	ft_putstr_fd("Congratulations ! Your Score is : ", 1);
	ft_putnbr_fd(data->moves + 1, 1);
	ft_putstr_fd(" Moves \n", 1);
	free_exit(data);
}

void	movements(t_lst *data)
{
	data->moves++;
	ft_putstr_fd("Number Of Movements Is : ", 1);
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
}
