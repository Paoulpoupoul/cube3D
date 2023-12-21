/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:09 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 15:08:02 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Setting up textures*/
int	set_textures(t_map *cfg, t_game *game)
{
// NORTH
	cfg->no.path = "./textures/Bricks1.xpm";
	cfg->no.img.img = mlx_xpm_file_to_image(game->win->mlx, cfg->no.path,
			&cfg->no.img.width, &cfg->no.img.height);
	if (cfg->no.img.img != NULL)
	{
		cfg->no.img.addr = mlx_get_data_addr(cfg->no.img.img, &cfg->no.img.bpp,
				&cfg->no.img.line_len, &cfg->no.img.endian);
	}
	else
		return (1);

// SOUTH
	cfg->so.path = "./textures/test2.xpm";
	cfg->so.img.img = mlx_xpm_file_to_image(game->win->mlx, cfg->so.path,
			&cfg->so.img.width, &cfg->so.img.height);
	if (cfg->so.img.img != NULL)
	{
		cfg->so.img.addr = mlx_get_data_addr(cfg->so.img.img, &cfg->so.img.bpp,
				&cfg->so.img.line_len, &cfg->so.img.endian);
	}
	else
		return (1);

// EAST
	cfg->ea.path = "./textures/test3.xpm";
	cfg->ea.img.img = mlx_xpm_file_to_image(game->win->mlx, cfg->ea.path,
			&cfg->ea.img.width, &cfg->ea.img.height);
	if (cfg->ea.img.img != NULL)
	{
		cfg->ea.img.addr = mlx_get_data_addr(cfg->ea.img.img, &cfg->ea.img.bpp,
				&cfg->ea.img.line_len, &cfg->ea.img.endian);
	}
	else
		return (1);

// WEST
	cfg->we.path = "./textures/test1.xpm";
	cfg->we.img.img = mlx_xpm_file_to_image(game->win->mlx, cfg->we.path,
			&cfg->we.img.width, &cfg->we.img.height);
	if (cfg->we.img.img != NULL)
	{
		cfg->we.img.addr = mlx_get_data_addr(cfg->we.img.img, &cfg->we.img.bpp,
				&cfg->we.img.line_len, &cfg->we.img.endian);
	}
	else	
		return (1);

	// F 220,100,0
	// C 225,30,0
	cfg->f.r = 220;
	cfg->f.g = 100;
	cfg->f.b = 0;

	cfg->c.r = 225;
	cfg->c.g = 30;
	cfg->c.b = 0;
	
	set_colors(cfg);
	return (0);
}
