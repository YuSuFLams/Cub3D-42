/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:27 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:34:17 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_special_char(char *line)
{
	size_t	length;
	size_t	i;
	char	*map_char;

	length = ft_strlen(line);
	map_char = "01NSWE";
	i = -1;
	while (++i < length)
		if (!ft_strchr(map_char, line[i]) && !is_space(line[i]))
			return (false);
	return (true);
}

void	check_char(char **n_map)
{
	int		i;
	char	*line;

	line = ft_strtrim(n_map[0], "\t\f\v\n\r ");
	check_last_first(line);
	free(line);
	i = -1;
	while (n_map[++i])
	{
		line = ft_strtrim(n_map[i], "\t\f\v\n\r ");
		check_sides_wall(line);
		if (!check_special_char(line))
			(ft_putstr_fd(ERR_OTHER_CHAR, 2, RED), exit(1));
		free(line);
	}
	line = ft_strtrim(n_map[i - 1], "\t\f\v\n\r ");
	check_last_first(line);
	free(line);
}

void	replace_spaces(char **str, int size_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size_map)
	{
		j = -1;
		while (str[i][++j])
			if (is_space(str[i][j]))
				str[i][j] = '*';
	}
}

void	checkspacemap(char **str, int l_map, int s_line)
{
	int	i;
	int	j;

	i = 0;
	while (++i < l_map - 1)
	{
		j = -1;
		while (++j < s_line)
		{
			if (str[i][j] == '0')
			{
				if ((j > 0 && (str[i][j - 1] == '*' || str[i][j - 1] == 0)) || \
				(j < s_line - 1 && (str[i][j + 1] == '*' || \
				str[i][j + 1] == 0)) || (i > 0 && (str[i - 1][j] == '*' || \
				str[i - 1][j] == 0)) || (i < l_map - 1 && (str[i + 1][j] == '*' \
				|| str[i + 1][j] == 0)))
				{
					ft_putstr_fd(ERR_MAP_INVALID, 2, RED);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

void	checkmap(char **n_map)
{
	int		s_line;
	int		l_map;
	char	**str;

	l_map = set_size_map(n_map);
	str = new_map_test(n_map, get_max(n_map, l_map), l_map);
	if (!str)
		exit(1);
	replace_spaces(str, l_map);
	s_line = ft_strlen(str[0]);
	checkspacemap(str, l_map, s_line);
	freesplit(str, 0);
}
