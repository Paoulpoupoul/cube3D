/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:53 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 16:02:47 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cub3d(t_map *conf, t_player *player)
{
	t_window	win;
	t_keys		keys;
	t_game		game;

	win = init_window();
	keys = init_keys();
	game = init_game(conf, player, &win, &keys);
	if (!set_textures(conf, &game))
		hooks(&game);
	else
		printf("Error\nTextures must be .xpm format.\n");	// printf
	c3d_exit(&game);
	mlx_destroy_image(game.win->mlx, game.win->img.img);
	mlx_destroy_display(game.win->mlx);
	free(game.win->mlx);
	return (0);
}
