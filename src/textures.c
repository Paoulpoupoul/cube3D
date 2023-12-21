/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:09 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 15:52:59 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Setting up textures*/
int	set_img_text(t_texture *dir, t_game *game)
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
