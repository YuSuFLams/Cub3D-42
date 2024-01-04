/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyer_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:26:26 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/21 16:57:22 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_num_player(char **map)
{
	int	i;
	int	j;
	int	num_player;

	i = -1;
	num_player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'E' || map[i][j] == 'W')
				num_player++;
	}
	return (num_player);
}

bool	player_exit(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'E' || map[i][j] == 'W')
				return (true);
	}
	return (false);
}

void	check_first(t_cub3d *vars)
{
	if (!player_exit(vars->n_map))
		(ft_putstr_fd(ERR_N0_PLAYER, 2, RED), exit (1));
	if (check_num_player(vars->n_map) != 1)
		(ft_putstr_fd(ERR_NO_ONE_PLAYER, 2, RED), exit(1));
}

void	get_pos_player(t_cub3d *vars)
{
	int	i;
	int	j;

	check_first(vars);
	i = -1;
	while (vars->n_map[++i])
	{
		j = -1;
		while (vars->n_map[i][++j])
		{
			if (vars->n_map[i][j] == 'N' || vars->n_map[i][j] == 'S' || \
				vars->n_map[i][j] == 'E' || vars->n_map[i][j] == 'W')
			{
				vars->pos.x = j;
				vars->pos.y = i;
				vars->t_ply = vars->n_map[i][j];
				return ;
			}
		}
	}
}
