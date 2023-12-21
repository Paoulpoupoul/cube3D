/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:28:56 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 15:20:06 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Texture initialization*/
/*t_texture	init_texture(void)
{
	t_texture	text;

	text.path = NULL;
	text.img = init_img();
	text.width = 128;
	text.height = 128;
	text.side = 0;
	return (text);
}*/

/*Color initialization*/
/*t_color	init_color(void)
{
	t_color	color;

	color.color = 0;
	color.raw = NULL;
	return (color);
}*/

/*Image initialization*/
/*t_img	init_img(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.width = 0;
	img.height = 0;
	img.bpp = 0;
	img.line_len = 0;
	img.endian = 0;
	return (img);
}*/

/*Map initialization*/
void	init_map_cfg(t_map *conf, t_player *player)
{
	conf->no.side = NO;
	conf->no.width = 32;
	conf->no.height = 32;
	conf->so.side = SO;
	conf->so.width = 32;
	conf->so.height = 32;
	conf->we.side = WE;
	conf->we.width = 32;
	conf->we.height = 32;
	conf->ea.side = EA;
	conf->ea.width = 32;
	conf->ea.height = 32;
	player->plane.x = FOV;
	player->plane.y = 0.0f;
}
