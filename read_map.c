/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:31:53 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/15 16:53:29 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(t_lst data)
{
	int		r;
	int		fd;
	char	*store;
	char	*temp;
	char	*join;

	store = ft_strdup("");
	fd = open (data.filename, O_RDONLY);
	if (fd < 0)
		invalid_args(3);
	temp = (char *) malloc (1000001 * sizeof(char));
	r = read (fd, temp, 100000);
	while (r > 0)
	{
		temp[r] = '\0';
		join = ft_strjoin(store, temp);
		free(store);
		store = join;
		r = read (fd, temp, 100000);
	}
	free(temp);
	close (fd);
	return (store);
}

void	check_args(t_lst data)
{
	const char	*after;

	after = ft_strchr(data.filename, '.');
	if (!(after && ft_strcmp("ber", after + 1) == 0))
		invalid_args(2);
	else
		return ;
}
