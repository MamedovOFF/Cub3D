/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:56:18 by spurple           #+#    #+#             */
/*   Updated: 2022/07/01 20:34:41 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include "../libft/libft.h"
# define MALLOC_FAILURE "Error\nmalloc() returned NULL"

# define WIDTH 1800
# define HEIGHT 1200
# define SCALE 5
# define MOVESPEED 0.1
# define MOUSESPEED 0.1
# define ROTATESPEED 0.1

typedef struct s_texture
{
	int			width;
	int			height;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*path;
}				t_texture;

typedef struct s_config
{
	t_texture	*no_texture;
	t_texture	*so_texture;
	t_texture	*we_texture;
	t_texture	*ea_texture;
	int			c;
	int			f;
	int			map_length;
	double		wall_x;
}				t_config;

typedef struct s_pers_pos
{
	double		x;
	double		y;
	char		side;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_pers_pos;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		mouse_left;
	int		mouse_right;
}				t_key;

typedef struct s_add
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	int		hit;
	int		side;
}				t_dda;

typedef struct s_cub
{
	int			x;
	int			prev_x;
	double		z;
	double		prev_z;
	char		**map;
	int			map_len;
	t_dda		*dda;
	t_pers_pos	*pers;
	t_config	*config;
	t_mlx		*lib_mlx;
	t_key		*key;
}				t_cub;

t_cub	*parsing(int argc, char **argv);
void	set_images(t_cub *cub);
t_mlx	*init_lib_mlx(t_cub *cub);
int		len_2d_str(char **str);
void	str_2d_clean(char **s, size_t l);
void	ft_cast_rays(t_cub *map);
void	clear_str_arr(char	**arr);
void	clear_int_arr(int **arr, int len);
size_t	count_words(char const *str, char c);
void	clean_cub(t_cub *cub);
void	clean_config(t_config *conf, t_cub *cub);
void	exit_with_error(char *message, t_cub *cub);
void	str_2d_clean(char **s, size_t l);
void	draw_minimap(t_cub *cub);
int		create_rgb(int r, int g, int b);
void	put_pixel(int x, int y, t_mlx *lib_mlx, int color);
void	init_t_add(t_cub *cub, int x);
void	calc_ray(t_cub *cub);
void	hit(t_cub *cub);
void	side(t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);
void	move(t_cub *cub);
void	move_w(t_cub *cub);
void	move_s(t_cub *cub);
void	move_a(t_cub *cub);
void	move_d(t_cub *cub);
void	move_mouse(t_cub *cub, double z);
int		ft_exit(t_cub *cub);
#endif