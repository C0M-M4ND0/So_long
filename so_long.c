/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:11:31 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/06 09:57:13 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key, t_data *v)
{
	if (key == 53)
	{
		free(v->str);
		exit(0);
	}
	return (0);
}

int	close_red(t_data *v)
{
	free(v->str);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	v;

	v = (t_data){};
	if (ac == 2)
	{
		if (ft_check_map(av[1], &v) == 1)
			return (0);
		v.mlx = mlx_init();
		v.i = count(v.str, v);
		v.pw = ft_strlen (v.str[0]) * 40;
		v.ph = v.i * 40;
		v.win = mlx_new_window(v.mlx, v.pw, v.ph, "SoLong");
		ft_put_images(v);
		v.temp = ft_itoa(v.number++);
		v.img = mlx_xpm_file_to_image(v.mlx, "./img/w.xpm", &v.wd, &v.hg);
		mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
		mlx_string_put(v.mlx, v.win, 0, 0, 0xFF0000, v.temp);
		mlx_key_hook(v.win, ft_close, &v);
		mlx_hook(v.win, 17, 1L << 0, close_red, &v);
		mlx_hook(v.win, 02, 1L << 0, move_player, &v);
		mlx_loop_hook(v.mlx, enmy, &v);
		mlx_loop(v.mlx);
	}
	else
		return (printf("ERROR\n"), 0);
}
