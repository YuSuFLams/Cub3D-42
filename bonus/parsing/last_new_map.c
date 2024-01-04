/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_new_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:08:40 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:54:42 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*line_without_new_line(char *line)
{
	char	*p;

	p = ft_strchr(line, '\n');
	if (p)
		return (ft_substr(line, 0, p - line));
	return (ft_strdup(line));
}

char	*get_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (!len)
		return (ft_strdup(""));
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t' \
	|| line[len - 1] == '\n' || line[len - 1] == '\r'))
		len--;
	if (len == 0)
		return (ft_strdup(""));
	return (ft_substr(line, 0, len));
}

void	new_map_1(t_cub3d *vars)
{
	char	**map;
	int		i;

	map = vars->n_map;
	i = 0;
	while (map[i])
	{
		vars->n_map[i] = get_line(map[i]);
		i++;
	}
	vars->n_map[i] = NULL;
}

char	*new_line(char *line, int max_line)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = (char *)ft_calloc((max_line + 1), sizeof(char));
	if (!new_line)
		(ft_putstr_fd(ERR_MEMORY, 2, RED), exit(1));
	if ((int)ft_strlen(line) < max_line)
	{
		while (line[i] && line[i] != '\n')
		{
			new_line[i] = line[i];
			i++;
		}
		while (i < max_line)
			new_line[i++] = ' ';
		new_line[i] = '\0';
	}
	else
		new_line = line_without_new_line(line);
	return (new_line);
}

char	**new_map(char **old_map)
{
	char	**new_map;
	int		max_line;
	int		nbr_lines;
	int		i;

	nbr_lines = set_size_map(old_map);
	max_line = get_max(old_map, nbr_lines);
	new_map = (char **)ft_calloc((nbr_lines + 1), sizeof(char *));
	if (!new_map)
		(ft_putstr_fd(ERR_MEMORY, 2, RED), exit(1));
	i = 0;
	while (old_map[i])
	{
		if ((int)ft_strlen(old_map[i]) < max_line)
			new_map[i] = new_line(old_map[i], max_line);
		else
			new_map[i] = ft_strdup(old_map[i]);
		i++;
	}
	new_map[i] = NULL;
	freesplit(old_map, 0);
	return (new_map);
}
