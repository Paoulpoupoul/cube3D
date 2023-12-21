/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:28:56 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 13:24:58 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Texture initialization*/
t_texture	init_texture(void)
{
	t_texture	text;

	text.path = NULL;
	text.img = init_img();
	text.width = 128;
	text.height = 128;
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
	t_map	conf;

	conf.map = NULL;
	conf.no = init_texture();
	conf.no.side = NO;
	conf.so = init_texture();
	conf.so.side = SO;
	conf.we = init_texture();
	conf.we.side = WE;
	conf.ea = init_texture();
	conf.ea.side = EA;
	conf.f = init_color();
	conf.c = init_color();
	conf.spawn_dir = 0;
	return (conf);
}
