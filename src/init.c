/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:23 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Window initialization*/
t_window	init_window(void)
{
	t_window	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIN_W, WIN_H, "Cub3D");
	win.img.img = mlx_new_image(win.mlx, WIN_W, WIN_H);
	if (win.img.img != NULL)
		win.img.addr = mlx_get_data_addr(win.img.img, &win.img.bpp,
				&win.img.line_len, &win.img.endian);
	return (win);
}

/*Keys initialization*/
t_keys	init_keys(void)
{
	t_keys	keys;

	keys.w = 0;
	keys.a = 0;
	keys.s = 0;
	keys.d = 0;
	keys.esc = 0;
	keys.left = 0;
	keys.right = 0;
	// keys.tab = 0;				// pour minimap
	return (keys);
}

/*Game's configuration initialization*/
t_game	init_game(t_map *conf, t_player *player, t_window *win, t_keys *keys)
{
	t_game	game;

	game.conf = conf;
	game.player = player;
	game.win = win;
	game.ray = NULL;
	game.keys = keys;
	return (game);
}

