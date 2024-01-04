/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:36:01 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:35:01 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_valid_map(t_cub3d *vars)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = (char **)ft_calloc((vars->size_map + 1), sizeof(char *));
	if (!new_map)
		exit(1);
	i = -1;
	j = 0;
	while (vars->o_map[++i])
		if (!is_all_space(vars->o_map[i]))
			new_map[j++] = vars->o_map[i];
	new_map[j] = NULL;
	vars->n_map = (char **)ft_calloc((vars->size_map + 1), sizeof(char *));
	if (!vars->n_map)
		exit(1);
	i = 6;
	j = 0;
	while (new_map[i])
		vars->n_map[j++] = new_map[i++];
	vars->n_map[j] = NULL;
	if (set_size_map(vars->n_map) == 0)
		(ft_putstr_fd(ERR_MAP, 2, RED), exit(EXIT_FAILURE));
	(free(new_map), check_char(vars->n_map), checkmap(vars->n_map));
	get_pos_player(vars);
}
