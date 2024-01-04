/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:43:08 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/03 15:31:07 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	initialize_my_var(t_cub3d *vars)
{
	vars->img = NULL;
	vars->up_down_moves = 0;
	vars->right_left_moves = 0;
	vars->radius = 4;
	vars->rotation_angle = get_angle(vars);
	vars->move_speed = 50;
	vars->rotation_speed = 10 * M_PI / 180;
	vars->fov = FOV * (M_PI / 180);
	vars->num_rays = WINDOW_WIDTH / WALL_STRIP_WIDTH;
	vars->rays = ft_calloc(vars->num_rays, sizeof(int));
	if (vars->num_rays == 0)
		ft_error();
	vars->wall_hit_x = 0;
	vars->wall_hit_y = 0;
	vars->minimap_scale = 0.2;
	vars->pos.x = (vars->pos.x * TILE_SIZE) + TILE_SIZE / 2;
	vars->pos.y = (vars->pos.y * TILE_SIZE) + TILE_SIZE / 2;
	vars->window_width = vars->width * TILE_SIZE;
	vars->window_height = vars->height * TILE_SIZE;
	vars->img = mlx_new_image(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	render(void *param)
{
	t_cub3d	*vars;

	vars = (t_cub3d *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
		ft_up(vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
		ft_down(vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		ft_left(vars);
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
		ft_right(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		ft_rotate_right(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		ft_rotate_left(vars);
	else
	{
		vars->up_down_moves = 0;
		vars->right_left_moves = 0;
	}
	ft_draw(vars);
}

void	set_map(t_cub3d *vars)
{
	vars->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB", false);
	initialize_my_var(vars);
	ft_draw(vars);
	mlx_loop_hook(vars->mlx, &render, vars);
	mlx_loop(vars->mlx);
}
