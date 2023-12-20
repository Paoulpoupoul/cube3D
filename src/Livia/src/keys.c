/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:26 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/20 16:40:33 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press_handler(int keysym, t_game *game)
{
	// printf("key: %d\n", keysym);
	if (keysym == XK_z)
		game->keys->w = 1;
	if (keysym == XK_q)
		game->keys->a = 1;
	if (keysym == XK_s)
		game->keys->s = 1;
	if (keysym == XK_d)
		game->keys->d = 1;
	if (keysym == XK_Escape)
		game->keys->esc = 1;
	if (keysym == XK_Left)
		game->keys->left = 1;
	if (keysym == XK_Right)
		game->keys->right = 1;
	// if (keysym == XK_Tab)		// pour minimap
	// 	game->keys->tab = !(game->keys->tab);
	return (0);
}

int	key_release_handler(int keysym, t_game *game)
{
	if (keysym == XK_z)
		game->keys->w = 0;
	if (keysym == XK_q)
		game->keys->a = 0;
	if (keysym == XK_s)
		game->keys->s = 0;
	if (keysym == XK_d)
		game->keys->d = 0;
	if (keysym == XK_Escape)
		game->keys->esc = 0;
	if (keysym == XK_Left)
		game->keys->left = 0;
	if (keysym == XK_Right)
		game->keys->right = 0;
	return (0);
}
