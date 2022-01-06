/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:18:07 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:16:19 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	position_x(char **map, char c)
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	position_player_y(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_collection(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	c = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
