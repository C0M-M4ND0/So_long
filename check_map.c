/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:36:39 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/06 10:09:08 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_helper_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != 'P' && str[i][j] != 'C' && str[i][j] != '0'
				&& str[i][j] != '1' && str[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	if (ft_strchr(str, 'P') == 1 && ft_strchr(str, 'E') != 0
		&& ft_strchr(str, 'C') != 0)
		return (0);
	return (1);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map_f_2(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_line(str[0]) == 1)
		return (1);
	while (str[i] && str[i + 1])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strlen(str[i]) != ft_strlen(str[i + 1]))
				return (1);
			if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
				return (1);
			j++;
		}
		i++;
	}
	if (check_line(str[i]) == 1 || ft_helper_check(str) == 1)
		return (1);
	return (0);
}

int	ft_check_map(char *map, t_data *v)
{
	if (cheking(map, ".ber") == 0)
		return (printf("ERROR (map extension must be '.ber')\n"), 1);
	v->fd = open(map, O_RDONLY);
	while (1)
	{
		v->line = get_line(v->fd);
		if (!v->line)
			break ;
		v->helper = v->all_line;
		if (!v->helper)
		{
			v->helper = malloc(1);
			v->helper[0] = '\0';
		}
		v->all_line = ft_strjoin(v->helper, v->line);
		free(v->line);
		free(v->helper);
	}
	if (!v->all_line)
		return (free(v->all_line), printf("ERROR (Map Invalid) \n"), 1);
	v->str = ft_split(v->all_line, '\n');
	if (ft_check_map_f_2(v->str) == 1)
		return (free(v->str), printf("ERROR (Map Invalid) \n"), 1);
	return (0);
}
