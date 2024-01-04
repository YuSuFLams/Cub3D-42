/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:02:40 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 16:08:43 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_last_first(char *line)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	while (++i < len)
	{
		if (*(line + i) != '1' && !is_space(*(line + i)))
		{
			ft_putstr_fd("\033[1;36m\t\t\b\bERROR\n", 2, NULL);
			ft_putstr_fd("Your map is not surrounded by a wall.\n", 2, NULL);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_sides_wall(char *line)
{
	int	j;

	j = ft_strlen(line) - 1;
	if (*line != '1' || *(line + j) != '1')
	{
		ft_putstr_fd("\033[0;36m       Error checking sidewalls \n", 2, NULL);
		ft_putstr_fd("\033[0;36mYour map should ", 2, NULL);
		ft_putstr_fd("start and end sides by 1\n", 2, NULL);
		exit(EXIT_FAILURE);
	}
}

void	map_no_white_space(char **map)
{
	int	len;

	len = set_size_map(map) - 1;
	while (len >= 0 && is_all_space(map[len]))
		len--;
	while (len >= 0 && !is_all_space(map[len]))
		len--;
	if (len >= 0 && is_all_space(map[len]))
	{
		while (len >= 0 && is_all_space(map[len]))
			len--;
		if (len >= 0)
		{
			if ((ft_strstr(map[len], ",") || ft_strstr(map[len], "png")))
				return ;
			else
				(ft_putstr_fd(ERR_MAP_INVALID, 2, RED), exit(EXIT_FAILURE));
		}
	}
}
