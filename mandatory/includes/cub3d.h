/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:30:25 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:21:49 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <stdint.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include <stdarg.h> 
# include <limits.h>
# include <math.h>

# define FOV 90
# define TILE_SIZE 64
# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 800
# define WALL_STRIP_WIDTH 3

# define RED "\033[91m"

# define ERR_COUNT_NUM "You Must Have Three Numbers For Each Colors!\n\033[34m"
# define ERR_NUM_COLOR "Your Number of Each Colors Must Have Valid!\n\033[34m"
# define ERR_COLOR_FC "You Must Have Two Floor\n\033[34m"
# define ERR_COLOR_D  "You Must Have Four Direction!\n\033[34m"
# define ERR_MAP "ERROR: Your Map is Empty, Your Map Should Be Valid.\n\033[34m"
# define ERR_MEMORY "ERROR: Memory allocation failed.\n\033[34m"
# define ERR_MAP_INVALID "Map You Gave Me Is Invalid\n\033[34m"
# define ERR_OTHER_CHAR "\t    ERROR\nMap Contains Other Characters\n\033[34m"
# define ERR_PATH_DIRECTION "Path One Of Directions Is Invalid!\n\033[34m"
# define ERR_PATH_FLOOR "Path One Of Floor Is Invalid!\n\033[34m"
# define ERR_NO_ONE_PLAYER "\t   Error\nMore than one player in map\n\033[34m"
# define ERR_N0_PLAYER "     Error\nNo player in map\n\033[34m"
# define ERR_PATH "ERROR: Path One Of Directions Is Invalid!\n\033[34m"
# define ERR_PNG_SQUARE "ERROR: Your Texture Must Be Square!\n"

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_ray
{
	int	israydown;
	int	israyup;
	int	isright;
	int	isleft;
}	t_ray;

typedef struct s_pos_mouse
{
	int	x;
	int	y;
}	t_pos_mouse;

typedef struct s_cub3d
{
	char				*direction[4];
	char				*floor[2];
	char				**o_map;
	char				**n_map;
	char				**f;
	char				**c;
	int					size_map;
	int					width;
	char				**s;
	int					height;
	t_mlx				*mlx;
	t_mlx_image			*img;
	t_mlx_texture		*texture[4];
	t_mlx_key_cbdata	keydata;
	int					up_down_moves;
	int					right_left_moves;
	int					radius;
	double				rotation_angle;
	float				move_speed;
	double				rotation_speed;
	char				t_ply;
	t_pos				pos;
	double				fov;
	int					num_rays;
	int					*rays;
	t_ray				ray;
	float				distance;
	float				wall_hit_x;
	float				wall_hit_y;
	float				minimap_scale;
	float				window_width;
	float				window_height;
	int					wall_up_left;
	int					wall_left;
	int					wall_down;
	float				x_step;
	float				y_step;
	float				x_intercept;
	float				y_intercept;
	int					is_up;
	int					is_left;
	float				next_hor_inter_x;
	float				next_hor_inter_y;
	float				next_ver_inter_x;
	float				next_ver_inter_y;
	int					found_hor_hit;
	int					found_ver_hit;
	float				hor_wallhitx;
	float				hor_wallhity;
	float				hor_distance;
	float				ver_distance;
	float				ver_wallhitx;
	float				ver_wallhity;
	t_mlx_texture		*hes;

	t_pos_mouse			mouse;
}	t_cub3d;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
	int		x2;
	int		y2;
}	t_line;

// Cub3d Fonction

//-->Utils of Cub3d

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*set_read_line(char *line);
char	*ft_strchr(char *s, int c);
char	*set_next_line(char *line);
char	*read_line(int fd, char *line);
char	*ft_strjoin(char *s1, char *s2);

// src_libft
size_t	ft_strlen(const char *s);
int		set_size_map(char **s);
int		ft_atoi(const char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
void	freesplit(char **s, int i);
int		count(char const *s, char c);
bool	is_all_space(char *line);
char	*ft_strstr(char *str, char *to_find);
bool	is_space(char c);
void	*ft_calloc(size_t count, size_t size);
int		size_map(char *str);
void	free_all(t_cub3d *vars);
char	*ft_strtrim(char const *s1, char const *set);
int		count_comma(char *s);
int		digitcomma(char *s);
void	ft_bzero(void *s, size_t n);

//Parcing
void	check_name_map(char *map_name);
void	first_read_map(char *str, t_cub3d *vars);
void	set_direction(t_cub3d *vars);
void	set_pos(t_cub3d *vars, char *line);
char	*first_word(char *s);
void	check_valid_map(t_cub3d *vars);
void	check_file(t_cub3d *cub);

/////////////////////////////
char	*last_word(char *s);
char	*first_word(char *s);
int		count_dir_fl(char *s);
void	checkmap(char **n_map);
bool	player_exit(char **map);
void	check_char(char **n_map);
void	error_map(int fd, int flag);
void	check_sides_wall(char *line);
void	check_last_first(char *line);
bool	check_special_char(char *line);
int		check_num_player(char **map);
void	get_pos_player(t_cub3d *vars);
int		get_max( char **str, int size);
int		check_array_is_full(t_cub3d *vars);
void	replace_spaces(char **str, int size_map);
char	**new_map_test(char **str, int s_line, int len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd, char *color);
int		count_number_colors(char *str);
void	map_no_white_space(char **map);
void	checkspacemap(char **str, int l_map, int s_line);
////////////\//////////////\//////////////************************************
char	*get_line(char *line);
void	new_map_1(t_cub3d *vars);
char	**new_map(char **old_map);
char	*line_without_new_line(char *line);
char	*new_line(char *line, int max_line);
void	parsing(char *file_name, t_cub3d *vars);

void	load_image(t_cub3d *vars);

void	set_map(t_cub3d *vars);
void	ft_draw(t_cub3d *vars);
void	ft_error(void);
void	ft_cast_ray(t_cub3d *vars, int i, double ray_angle);
double	ft_normalize_angle(double angle);

int		get_rgb(int r, int g, int b, int a);
int		put_color_floor(t_cub3d *vars);
int		put_color_ceiling(t_cub3d *vars);
double	get_angle(t_cub3d *vars);
int		get_color_from_image(t_mlx_texture *text, int x, int y);
void	ft_up(t_cub3d *vars);
float	get_distance(t_cub3d *vars, float xa, float ya);
void	ft_directions(t_cub3d *vars, double ray_angle);
void	put_variable(t_cub3d *vars);
////update moves
void	ft_up(t_cub3d *vars);
void	ft_down(t_cub3d *vars);
void	ft_left(t_cub3d *vars);
void	ft_right(t_cub3d *vars);

///update_rotation
void	ft_rotate_right(t_cub3d *vars);
void	ft_rotate_left(t_cub3d *vars);

////update map
void	updated_map_up_down(t_cub3d *vars);
void	updated_map_right_left(t_cub3d *vars);

///shapes
void	draw_map(t_cub3d *vars, int h, int w);
void	draw_circle(void *data, int x, int y, int radius);
void	draw_line(t_cub3d *vars, int d, unsigned int color, double angle);

#endif