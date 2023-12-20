/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:40 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/20 15:40:53 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include	<string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_texture
{
	void	*so;
	void	*no;
	void	*ea;
	void	*we;
	t_rgb	fl;
	t_rgb	cl;
}	t_texture;

typedef struct s_cub3d
{
	int			fd;
	int			**map;
	char		**c_map;
	t_pos		map_s;
	t_pos		pl_pos;
	t_texture	txtr;
}	t_cub;

// parsing.c
int	parsing(t_cub *cub, char *file);

// parsing_2.c
int	check_file(char *file);
int	add_texture_to_mlx(t_cub *cub, char *file, void *img);
int	add_color_to(char *line, int *i, int *color);
int	check_line(char *line, int i);
int	check_parsing(t_cub *cub, int i);

// parsing_map.c
int	parsing_map(t_cub *cub, char *line);

// parsing_map_2.c
int	line_empty(char *line);
int	rest_empty(char **map, int j);
int	add_player_cord(t_cub *cub, int x, int y, char c);
int	char_to_map(char c);
int	check_map(t_cub *cub);

// err_msg.c
int	err_msg(char *msg);
int	errno_msg(char *msg, int err);

#endif