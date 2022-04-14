/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:48:53 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/15 16:23:04 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	l;
	int		i;

	i = 0;
	l = ft_strlen (s1) + ft_strlen (s2) + 1;
	str = (char *) malloc (l * sizeof(char));
	if (!str)
		return (0);
	while (*s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char	s[20] = "sara";
	char	s2[20] = "lahrach";
	printf("%s",ft_strjoin(s, s2));
}*/
