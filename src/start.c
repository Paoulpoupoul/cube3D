/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:53 by lkoletzk          #+#    #+#             */
/*   Updated: 2024/01/11 15:03:43 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_game game)
{
	c3d_exit(&game);
	mlx_destroy_image(game.win->mlx, game.win->img.img);
	mlx_destroy_display(game.win->mlx);
	free(game.win->mlx);
	return (0);
}

int	cub3d(t_map *conf, t_player *player)
{
	t_window	win;
	t_keys		keys;
	t_game		game;

	win = init_window();
	if (!win.mlx || !win.win)
	{
		free(win.mlx);
		printf ("Window's init failed.\n");
		return (1);
	}
	keys = init_keys();
	game = init_game(conf, player, &win, &keys);
	if (!set_textures(conf, &game))
		hooks(&game);
	else
		printf("Error\nTextures must be .xpm format.\n");
	exit_game(game);
	return (0);
}
