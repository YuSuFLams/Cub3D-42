/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:02:41 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/08 14:35:46 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	size_map(char *str)
{
	char	*line;
	int		size_map;
	int		fd;

	size_map = 0;
	fd = open(str, O_RDONLY);
	error_map(fd, 1);
	line = get_next_line(fd);
	while (line)
	{
		size_map++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	error_map(fd, 0);
	return (size_map);
}

int	get_max(char **str, int size)
{
	int	max;
	int	i;
	int	len;

	max = ft_strlen(str[0]);
	i = -1;
	while (++i < size)
	{
		len = ft_strlen(str[i]);
		if (len > max)
			max = len;
	}
	return (max);
}
