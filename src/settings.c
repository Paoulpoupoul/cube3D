/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:41 by lkoletzk          #+#    #+#             */
/*   Updated: 2024/01/11 11:49:30 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*------------------------ Setting up colors -----------------------*/
static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_colors(t_map *cfg)
{
	cfg->f.color = create_trgb(0, cfg->f.r, cfg->f.g, cfg->f.b);
	cfg->c.color = create_trgb(0, cfg->c.r, cfg->c.g, cfg->c.b);
}

/*----------------------- Setting up textures ----------------------*/
static int	set_img_text(t_texture *dir, t_game *game)
{
	dir->img.img = mlx_xpm_file_to_image(game->win->mlx, dir->path,
			&dir->img.width, &dir->img.height);
	if (dir->img.img != NULL)
	{
		dir->img.addr = mlx_get_data_addr(dir->img.img, &dir->img.bpp,
				&dir->img.line_len, &dir->img.endian);
	}
	else
		return (1);
	return (0);
}

int	set_textures(t_map *cfg, t_game *game)
{
	if (set_img_text(&cfg->no, game) || set_img_text(&cfg->so, game)
		|| set_img_text(&cfg->ea, game) || set_img_text(&cfg->we, game))
		return (1);
	set_colors(cfg);
	return (0);
}
