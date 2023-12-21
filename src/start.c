/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:11:53 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cub3d(t_map *conf, t_player *player)
{
	t_window	win;
	t_keys		keys;
	t_game		game;

// On continue d'initialiser la structure du jeu
	win = init_window();
	keys = init_keys();
	game = init_game(conf, player, &win, &keys);

// On configure les textures (les couleurs aussi, un jour) à la mano ...
// Et si pas de pbm, on lance la MLX !!
	if (!set_textures(conf, &game))
		hooks(&game);
	else
		printf("Error\nTextures must be .xpm format.\n");

	c3d_exit(&game);
	mlx_destroy_image(game.win->mlx, game.win->img.img);
	mlx_destroy_display(game.win->mlx);
	free(game.win->mlx);
	return (0);
}
