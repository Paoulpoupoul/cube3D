/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:28:56 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Texture initialization*/
t_texture	init_texture(void)
{
	t_texture	text;

	text.path = NULL;
	text.img = init_img();
	text.width = 32;
	text.height = 32;
	text.side = 0;
	return (text);
}

/*Color initialization*/
t_color	init_color(void)
{
	t_color	color;

	color.color = 0;
	color.raw = NULL;
	return (color);
}

/*Image initialization*/
t_img	init_img(void)
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
}

/*Map initialization*/
t_map	init_map_cfg(void)
{
	t_map	map_cfg;

	map_cfg.map = NULL;
	map_cfg.no = init_texture();
	map_cfg.no.side = NO;
	map_cfg.so = init_texture();
	map_cfg.so.side = SO;
	map_cfg.we = init_texture();
	map_cfg.we.side = WE;
	map_cfg.ea = init_texture();
	map_cfg.ea.side = EA;
	map_cfg.f = init_color();
	map_cfg.c = init_color();
	map_cfg.spawn_dir = 0;
	return (map_cfg);
}
