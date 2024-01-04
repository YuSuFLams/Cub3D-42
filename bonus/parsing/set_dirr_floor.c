/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dirr_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:12:03 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/16 00:56:31 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_dir(t_cub3d *vars, char *line, int i)
{
	char	*new_path;

	if (count_dir_fl(line) != 2)
		(ft_putstr_fd(ERR_PATH_DIRECTION, 2, RED), exit(EXIT_FAILURE));
	new_path = last_word(line);
	if (!vars->direction[i])
		vars->direction[i] = ft_strdup(new_path);
	free(new_path);
}

void	set_floor(t_cub3d *vars, char *line, int i)
{
	char	*n_path;

	n_path = last_word(line);
	if (count_dir_fl(line) != 2 || !digitcomma(n_path) || \
	count_comma(n_path) != 2)
		(ft_putstr_fd(ERR_PATH_FLOOR, 2, RED), free(n_path), exit(1));
	if (!vars->floor[i])
		vars->floor[i] = ft_strdup(n_path);
	free(n_path);
}

void	set_pos(t_cub3d *vars, char *line)
{
	char	*sub_line;

	sub_line = first_word(line);
	if (!sub_line)
		return ;
	if (!ft_strcmp(sub_line, "NO") || !ft_strcmp(sub_line, "N"))
		set_dir(vars, line, 0);
	else if (!ft_strcmp(sub_line, "SO") || !ft_strcmp(sub_line, "S"))
		set_dir(vars, line, 1);
	else if (!ft_strcmp(sub_line, "WE") || !ft_strcmp(sub_line, "W"))
		set_dir(vars, line, 2);
	else if (!ft_strcmp(sub_line, "EA") || !ft_strcmp(sub_line, "E"))
		set_dir(vars, line, 3);
	else if (!ft_strcmp("F", sub_line))
		set_floor(vars, line, 0);
	else if (!ft_strcmp("C", sub_line))
		set_floor(vars, line, 1);
	free(sub_line);
}

bool	check_colors(t_cub3d *vars, int i)
{
	int	t[3];
	int	k;
	int	j;

	if (count_number_colors(vars->floor[i]) != 3)
		(ft_putstr_fd(ERR_COUNT_NUM, 2, RED), exit(EXIT_FAILURE));
	if (!i)
		vars->f = ft_split(vars->floor[0], ',');
	else
		vars->c = ft_split(vars->floor[1], ',');
	k = -1;
	while (++k < 3)
	{
		if (!i)
			t[k] = ft_atoi(vars->f[k]);
		else
			t[k] = ft_atoi(vars->c[k]);
	}
	j = -1;
	while (++j < 3)
		if (t[j] > 255)
			return (false);
	return (true);
}

void	set_direction(t_cub3d *vars)
{
	int	i;

	i = 0;
	while (i < 4)
		vars->direction[i++] = NULL;
	i = 0;
	while (i < 2)
		vars->floor[i++] = NULL;
	i = 0;
	while (vars->o_map[i])
	{
		set_pos(vars, vars->o_map[i]);
		i++;
	}
	if (check_array_is_full(vars) == 1)
		(ft_putstr_fd(ERR_COLOR_D, 2, RED), exit(EXIT_FAILURE));
	if (check_array_is_full(vars) == 2)
		(ft_putstr_fd(ERR_COLOR_FC, 2, RED), exit(EXIT_FAILURE));
	i = -1;
	while (++i < 2)
		if (!check_colors(vars, i))
			(ft_putstr_fd(ERR_NUM_COLOR, 2, RED), exit(EXIT_FAILURE));
}
