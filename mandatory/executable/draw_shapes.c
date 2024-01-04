/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:13:44 by abelkace          #+#    #+#             */
/*   Updated: 2024/01/01 21:54:53 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_map(t_cub3d *vars, int h, int w)
{
	char	**s;
	int		i;
	int		j;

	s = vars->n_map;
	i = 0;
	while (i >= 0 && i < h)
	{
		j = 0;
		while (i >= 0 && j < w)
		{
			mlx_putpixel(vars->img, j * 0.2, i * 0.2, 0xFFFFFFF);
			if (s[(int)(i / TILE_SIZE)][(int)(j / TILE_SIZE)] == '1')
				mlx_putpixel(vars->img, j * 0.2, i * 0.2, 0x000000FF);
			else if (s[(int)(i / TILE_SIZE)][(int)(j / TILE_SIZE)] == '0' \
			|| s[(int)(i / TILE_SIZE)][(int)(j / TILE_SIZE)] == ' ' || \
			s[(int)(i / TILE_SIZE)][(int)(j / TILE_SIZE)] == vars->t_ply)
				mlx_putpixel(vars->img, j * 0.2, i * 0.2, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_circle(void *data, int x, int y, int radius)
{
	int	i;
	int	j;

	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				mlx_putpixel(data, (x + j) * 0.2, (y + x) * 0.2, 0xFF0000ff);
			j++;
		}
		i++;
	}
}

void	draw_line(t_cub3d *vars, int d, unsigned int color, double angle)
{
	t_line	line;
	int		i;

	line.x2 = vars->pos.x + d * cos(angle);
	line.y2 = vars->pos.y + d * sin(angle);
	line.dx = line.x2 - vars->pos.x;
	line.dy = line.y2 - vars->pos.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_inc = line.dx / (float)line.steps;
	line.y_inc = line.dy / (float)line.steps;
	line.x = vars->pos.x;
	line.y = vars->pos.y;
	i = 0;
	while (i <= line.steps)
	{
		mlx_putpixel(vars->img, (int)round(line.x) * 0.2, \
		(int)round(line.y) * 0.2, color);
		line.x += line.x_inc;
		line.y += line.y_inc;
		i++;
	}
}
