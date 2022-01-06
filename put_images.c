/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:50:28 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:16:15 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_helper(char target, t_data v)
{
	if (target == '1')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, "./img/w.xpm", &v.w, &v.h);
		mlx_put_image_to_window(v.mlx, v.win, v.img, v.j * 40, v.i * 40);
	}
	if (target == '0')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, "./img/b.xpm", &v.w, &v.h);
		mlx_put_image_to_window(v.mlx, v.win, v.img, v.j * 40, v.i * 40);
	}
	if (target == 'P')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, "./img/p.xpm", &v.w, &v.h);
		mlx_put_image_to_window(v.mlx, v.win, v.img, v.j * 40, v.i * 40);
	}
	if (target == 'C')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, "./img/c.xpm", &v.w, &v.h);
		mlx_put_image_to_window(v.mlx, v.win, v.img, v.j * 40, v.i * 40);
	}
	if (target == 'E')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, "./img/e.xpm", &v.w, &v.h);
		mlx_put_image_to_window(v.mlx, v.win, v.img, v.j * 40, v.i * 40);
	}
}

void	ft_put_images(t_data v)
{
	v.i = 0;
	while (v.str[v.i])
	{
		v.j = 0;
		while (v.str[v.i][v.j])
		{
			ft_helper(v.str[v.i][v.j], v);
			v.j++;
		}
		v.i++;
	}
}
