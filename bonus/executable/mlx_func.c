/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:08:24 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 13:15:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_rgb(int r, int g, int b, int a)
{
	int	type_color;

	type_color = (r << 24) | (g << 16) | (b << 8) | (a);
	return (type_color);
}

int	put_color_floor(t_cub3d *vars)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	type_color;

	r = ft_atoi(vars->f[0]);
	g = ft_atoi(vars->f[1]);
	b = ft_atoi(vars->f[2]);
	a = 255;
	type_color = get_rgb(r, g, b, a);
	return (type_color);
}

int	put_color_ceiling(t_cub3d *vars)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	type_color;

	r = ft_atoi(vars->c[0]);
	g = ft_atoi(vars->c[1]);
	b = ft_atoi(vars->c[2]);
	a = 255;
	type_color = get_rgb(r, g, b, a);
	return (type_color);
}

double	get_angle(t_cub3d *vars)
{
	double	angle;

	angle = 0.0;
	if (vars->t_ply == 'N')
		angle = 3 * M_PI / 2;
	else if (vars->t_ply == 'S')
		angle = M_PI / 2;
	else if (vars->t_ply == 'E')
		angle = 0;
	else if (vars->t_ply == 'W')
		angle = M_PI;
	return (angle);
}

int	get_color_from_image(t_mlx_texture *text, int x, int y)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	a;

	if (x < 0 || x >= (int)text->width || y < 0 || y >= (int)text->height)
		return (0);
	r = text->pixels[(y * text->height + x) * text->bytes_per_pixel];
	g = text->pixels[(y * text->height + x) * text->bytes_per_pixel + 1];
	b = text->pixels[(y * text->height + x) * text->bytes_per_pixel + 2];
	a = text->pixels[(y * text->height + x) * text->bytes_per_pixel + 3];
	color = get_rgb(r, g, b, a);
	return (color);
}
