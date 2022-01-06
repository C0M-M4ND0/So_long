/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:46:43 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:15:34 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr( char **str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count(char **str, t_data v)
{
	v.i = 0;
	while (str[v.i])
	{
		v.j = 0;
		while (str[v.i][v.j])
		{
			v.j++;
		}
		v.i++;
	}
	return (v.i);
}

int	ft_exit(t_data *v)
{
	mlx_destroy_window(v->mlx, v->win);
	free(v->str);
	printf("YOU WIN , RESTART PROGRAM TO PLAY AGAIN \n");
	exit(0);
}
