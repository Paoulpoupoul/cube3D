/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:18 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Setup hooks*/ 
void	hooks(t_game *game)
{
	mlx_hook(game->win->win, KeyPress, KeyPressMask, &key_press_handler, game);
	mlx_hook(game->win->win, KeyRelease, KeyReleaseMask, &key_release_handler, game);
	mlx_hook(game->win->win, DestroyNotify, StructureNotifyMask, &mlx_loop_end, game->win->mlx);
	mlx_loop_hook(game->win->mlx, &raycasting, game);
	mlx_loop(game->win->mlx);
}
