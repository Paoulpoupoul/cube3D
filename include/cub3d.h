/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:50 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 14:47:39 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <float.h>
# include <math.h>
# include <limits.h>

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"

# define SPAWN "NSEW"
# define COLLISIONS "0NSEW"

# define WIN_W 1280
# define WIN_H 720

# define FOV 0.9f // Champ de vision/Angle caméra

# define moveSpeed 0.05f
# define rotSpeed 0.05f
# define slideSpeed 0.05f

typedef enum e_side
{
	NO,
	SO,
	EA,
	WE,
	MAX
}	t_side;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_window;

typedef struct s_texture
{
	char	*path;
	t_img	img;
	int		width;
	int		height;
	int		side;
}	t_texture;

typedef struct s_color
{
	char	*raw;
	int		r;
	int		g;
	int		b;
	int		color;
}	t_color;

typedef struct s_map_cfg
{
	char		**map;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	t_color		f;
	t_color		c;
	char		spawn_dir;
}	t_map;

typedef struct s_player
{
	t_point	pos;
	t_point	dir;
	t_point	plane;
}	t_player;

typedef struct s_ray
{
	t_point	rayDir;
	t_point	sideDist;
	t_point	deltaDist;
	t_coord	map;
	t_coord	step;
	int		line;
}	t_ray;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
	int	esc;
	// int	tab;			// pour minimap
}	t_keys;

typedef struct s_game
{
	t_window	*win;
	t_map		*conf;
	t_player	*player;
	t_ray		*ray;
	t_keys		*keys;
}	t_game;


/* ----- Structure initialization ----- */
t_texture		init_texture(void);
t_color			init_color(void);
t_img			init_img(void);
t_map			init_map_cfg(void);
t_window		init_window(void);
t_keys			init_keys(void);
t_game			init_game(t_map *conf, t_player *player, t_window *win, t_keys *keys);
void			set_colors(t_map *conf);
int				set_textures(t_map *conf, t_game *game);

/* ----- Gaming ----- */
int				cub3d(t_map *conf, t_player *ray);
void			hooks(t_game *data);
int				key_press_handler(int keysym, t_game *data);
int				key_release_handler(int keysym, t_game *data);

/* ----- Raycasting ----- */
int				raycasting(t_game *game);
t_ray			init_ray(void);

/* ----- Moves ----- */
int				event(t_game *game);
// void			walk(t_game *game);
// void			slide(t_game *game);
// void			rotate(t_game *game);

/* ----- Game ----- */
void			ray_update(t_game *data, int i, t_ray *ray);
float			f_abs(float f);

/* ----- Utils ----- */
int				c3d_exit(t_game *data);
void			free_conf(t_map conf);

void			draw(t_game *data, float dist, int side);
int				get_pix_color(t_img *tex, int x, int y);
void			img_pix_put(t_img *img, int x, int y, int color);
int				draw_end(int height);
int				draw_start(int height);

#endif
