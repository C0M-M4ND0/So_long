/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:17:08 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:17:14 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct t_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		i;
	int		j;
	int		c;
	char	*helper;
	int		wd;
	int		hg;
	int		number;
	int		pw;
	int		ph;
	char	*temp;
	int		x;
	int		y;
	char	*all_line;
	int		fd;
	char	*line;
	char	**str;
	int		w;
	int		h;
}t_data;

char	*ft_strrchr(const char *s, char c);
int		cheking(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*get_line(int fd);
char	**ft_split(char const *str, char c);
int		ft_strchr(char **str, char c);
int		ft_check_map(char *map, t_data *v);
int		ft_check_map_f_2(char **str);
int		check_line(char *str);
int		ft_helper_check(char **str);
int		count(char **str, t_data value);
void	ft_put_images(t_data value);
void	ft_helper(char target, t_data value);
int		move_player(int key, t_data *value);
int		position_x(char **map, char c);
int		position_player_y(char **map);
int		count_collection(char **map);
char	*ft_itoa(int n);
int		enmy(t_data *v);
int		ft_exit(t_data *v);

#endif
