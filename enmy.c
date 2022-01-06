/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enmy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:36:20 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:15:49 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enmy_right(t_data *v, int i, int j)
{
	v->img = mlx_xpm_file_to_image(v->mlx, "./img/enr.xpm", &v->wd, &v->hg);
	mlx_put_image_to_window(v->mlx, v->win, v->img, j * 40, i * 40);
	if (v->str[i][j - 1] != '1' && v->str[i][j - 1] != 'C'
		&& v->str[i][j - 1] != 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/b.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, (j - 1) * 40, i * 40);
	}
	if (v->str[i][j] == 'P')
	{
		mlx_destroy_window(v->mlx, v->win);
		free(v->str);
		printf("YOU LOSE, RESTART PROGRAM TO PLAY AGAIN \n");
		exit(0);
	}
}

int	move_enmy_left(t_data *v, int i, int j)
{
	if (v->str[i][j] == '1' || v->str[i][j] == 'C' || v->str[i][j] == 'E')
		j--;
	v->img = mlx_xpm_file_to_image(v->mlx, "./img/enl.xpm", &v->wd, &v->hg);
	mlx_put_image_to_window(v->mlx, v->win, v->img, j * 40, i * 40);
	if (v->str[i][j + 1] != '1' && v->str[i][j + 1] != 'C'
		&& v->str[i][j + 1] != 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/b.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, (j + 1) * 40, i * 40);
	}
	if (v->str[i][j] == 'P')
	{
		mlx_destroy_window(v->mlx, v->win);
		free(v->str);
		printf("YOU LOSE, RESTART PROGRAM TO PLAY AGAIN \n");
		exit(0);
	}
	return (-1);
}

int	posit_y(char **map, int i, char c)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == c)
			return (j);
		j++;
	}
	return (0);
}

int	y_p(t_data *v, int i)
{
	int	j;

	j = 0;
	j = posit_y(v->str, i, '0');
	if (j == 0)
		i++;
	return (i);
}

int	enmy(t_data *v)
{
	static int	ref;
	static int	j;
	static int	si;
	static int	p;
	static int	i;

	i = y_p(v, i);
	if (p == 0)
		p = posit_y(v->str, i, '0');
	if (j == p - 1 || j == 0)
	{
		j = p;
		si = 1;
	}
	if (ref++ == 1000)
	{
		if (v->str[i][j] != '1' && v->str[i][j] != 'C'
			&& v->str[i][j] != 'E' && si == 1)
			move_enmy_right(v, i, j++);
		else if ((v->str[i][j - 1] != '1' && v->str[i][j - 1] != 'C'
			&& v->str[i][j - 1] != 'E') || (si == 1 || si == -1))
			si = move_enmy_left(v, i, j--);
		ref = 0;
	}
	return (0);
}
