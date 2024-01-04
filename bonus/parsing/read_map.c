/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:05:59 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:57:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	first_read_map(char *str, t_cub3d *vars)
{
	int		i;
	int		fd;
	char	*line;

	vars->size_map = size_map(str);
	fd = open(str, O_RDONLY);
	error_map(fd, 1);
	vars->o_map = (char **)ft_calloc(vars->size_map + 1, sizeof(char *));
	if (!vars->o_map)
		(ft_putstr_fd(ERR_MEMORY, 2, RED), exit(1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		(ft_putstr_fd(ERR_MAP, 2, RED), free(line), exit(1));
	while (line)
	{
		vars->o_map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	vars->o_map[i] = NULL;
	error_map(fd, 0);
}

char	**new_map_test(char **str, int s_line, int len)
{
	char	**new_s;
	int		j;
	int		i;
	int		str_length;

	new_s = (char **)ft_calloc((len + 1), sizeof(char *));
	if (!new_s)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < len)
	{
		str_length = ft_strlen(str[i]);
		new_s[i] = (char *)ft_calloc((s_line + 1), sizeof(char));
		if (!new_s[i])
			exit(EXIT_FAILURE);
		j = -1;
		while (++j < str_length && str[i][j] != '\n')
			new_s[i][j] = str[i][j];
		while (j < s_line)
			new_s[i][j++] = '*';
		new_s[i][j] = '\0';
	}
	new_s[len] = NULL;
	return (new_s);
}
