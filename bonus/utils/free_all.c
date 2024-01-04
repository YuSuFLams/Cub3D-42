/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:48:34 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/31 15:48:55 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	delete_texture(t_cub3d *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (vars->texture[i] != NULL)
			mlx_delete_texture(vars->texture[i]);
}

void	free_color(t_cub3d *vars)
{
	int	i;

	i = -1;
	while (++i < 3)
		free(vars->c[i]);
	free(vars->c);
	i = -1;
	while (++i < 3)
		free(vars->f[i]);
	free(vars->f);
}

void	free_direction(t_cub3d *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(vars->direction[i]);
}

void	free_floor(t_cub3d *vars)
{
	int	i;

	i = -1;
	while (++i < 2)
		free(vars->floor[i]);
}

void	free_all(t_cub3d *vars)
{
	delete_texture(vars);
	free_direction(vars);
	free_floor(vars);
	free_color(vars);
	freesplit(vars->o_map, 0);
	freesplit(vars->s, 0);
	free(vars->rays);
	free(vars);
}
