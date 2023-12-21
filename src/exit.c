/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:31:53 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_textures(t_map *conf, t_window *win)
{
	if (conf->no.img.img != NULL)
		mlx_destroy_image(win->mlx, conf->no.img.img);
	if (conf->so.img.img != NULL)
		mlx_destroy_image(win->mlx, conf->so.img.img);
	if (conf->we.img.img != NULL)
		mlx_destroy_image(win->mlx, conf->we.img.img);
	if (conf->ea.img.img != NULL)
		mlx_destroy_image(win->mlx, conf->ea.img.img);
}

int	c3d_exit(t_game *game)
{
	free_textures(game->conf, game->win);
	if (game->win->win != NULL)
	{
		mlx_destroy_window(game->win->mlx, game->win->win);
		game->win->win = NULL;
	}
	return (0);
}
