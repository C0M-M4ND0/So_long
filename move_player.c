/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 11:04:41 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:16:11 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(t_data *v)
{
	v->i = position_player_y(v->str);
	v->j = position_x(v->str, 'P');
	v->c = count_collection(v->str);
	if (v->str[v->i + 1][v->j] != '1'
		&& v->str[v->i + 1][v->j] != 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/p_dw.xpm",
				&v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, v->j * 40, (v->i + 1) * 40);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/b.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, (v->j) * 40, v->i * 40);
		v->str[v->i][v->j] = '0';
		v->str[v->i + 1][v->j] = 'P';
		v->temp = ft_itoa(v->number++);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/w.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
		mlx_string_put(v->mlx, v->win, 0, 0, 0xFF0000, v->temp);
	}
	else if (v->str[v->i + 1][v->j] == 'E' && v->c == 0)
	{
		ft_exit(v);
	}
	return (0);
}

int	move_up(t_data *v)
{
	v->i = position_player_y(v->str);
	v->j = position_x(v->str, 'P');
	v->c = count_collection(v->str);
	if (v->str[v->i - 1][v->j] != '1'
		&& v->str[v->i - 1][v->j] != 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/p_up.xpm",
				&v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, v->j * 40, (v->i - 1) * 40);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/b.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, (v->j) * 40, v->i * 40);
		v->str[v->i][v->j] = '0';
		v->str[v->i - 1][v->j] = 'P';
		v->temp = ft_itoa(v->number++);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/w.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
		mlx_string_put(v->mlx, v->win, 0, 0, 0xFF0000, v->temp);
	}
	else if (v->str[v->i - 1][v->j] == 'E' && v->c == 0)
	{
		ft_exit(v);
	}
	return (0);
}

int	move_left(t_data *v)
{
	v->i = position_player_y(v->str);
	v->j = position_x(v->str, 'P');
	v->c = count_collection(v->str);
	if (v->str[v->i][v->j - 1] != '1'
		&& v->str[v->i][v->j - 1] != 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/p_l.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, (v->j - 1) * 40, v->i * 40);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/b.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, (v->j) * 40, v->i * 40);
		v->str[v->i][v->j] = '0';
		v->str[v->i][v->j - 1] = 'P';
		v->temp = ft_itoa(v->number++);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/w.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
		mlx_string_put(v->mlx, v->win, 0, 0, 0xFF0000, v->temp);
	}
	else if (v->str[v->i][v->j - 1] == 'E' && v->c == 0)
	{
		ft_exit(v);
	}
	return (0);
}

int	move_right(t_data *v)
{
	v->i = position_player_y(v->str);
	v->j = position_x(v->str, 'P');
	v->c = count_collection(v->str);
	if (v->str[v->i][v->j + 1] != '1'
		&& v->str[v->i][v->j + 1] != 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/p.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, (v->j + 1) * 40, v->i * 40);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/b.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win,
			v->img, (v->j) * 40, v->i * 40);
		v->str[v->i][v->j] = '0';
		v->str[v->i][v->j + 1] = 'P';
		v->temp = ft_itoa(v->number++);
		v->img = mlx_xpm_file_to_image(v->mlx, "./img/w.xpm", &v->wd, &v->hg);
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
		mlx_string_put(v->mlx, v->win, 0, 0, 0xFF0000, v->temp);
	}
	else if (v->str[v->i][v->j + 1] == 'E' && v->c == 0)
	{
		ft_exit(v);
	}
	return (0);
}

int	move_player(int key, t_data *v)
{
	if (key == 2)
		move_right(v);
	if (key == 1)
		move_down(v);
	if (key == 0)
		move_left(v);
	if (key == 13)
		move_up(v);
	return (0);
}
