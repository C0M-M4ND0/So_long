/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:57:02 by oabdelha          #+#    #+#             */
/*   Updated: 2022/01/05 12:15:38 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

int	cheking(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s1 = ft_strrchr(s1, '.');
	if (s1 == NULL)
		return (0);
	while (s2[i])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*get_line(int fd)
{
	int		i;
	char	buff[1];
	char	str[9999];
	char	*line;

	i = 0;
	str[0] = '\0';
	while ((read(fd, buff, 1)) != 0)
	{	
		str[i] = buff[0];
		str[i + 1] = '\0';
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	i = -1;
	while (str[++i])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	l = ft_strlen(s2);
	temp = (char *)malloc(i + l + 1);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		temp[i++] = *s1++;
	while (*s2)
		temp[i++] = *s2++;
	temp[i] = '\0';
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
