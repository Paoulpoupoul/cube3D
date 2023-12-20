/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:39:13 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/20 17:51:19 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*Manage forward and backward movements*/
static void	walk(t_game *game)
{
	int		dir;
	t_point old;
	t_point new;

	dir = 1;
	old.x = game->player->dir.x;
	old.y = game->player->dir.y;
	if (game->keys->s)
		dir = -1;
	new.x = game->player->pos.x + (dir * old.x * moveSpeed);
	new.y = game->player->pos.y + (dir * old.y * moveSpeed);
// Collision management
	if (ft_ischarset(game->conf->map[(int)(new.y)][(int)(game->player->pos.x)],
		COLLISIONS))
		game->player->pos.y = new.y;
	if (ft_ischarset(game->conf->map[(int)(game->player->pos.y)][(int)(new.x)],
		COLLISIONS))
		game->player->pos.x = new.x;
}

/*Manage side movements*/
static void	slide(t_game *game)
{
	int		dir;
	t_point old;
	t_point new;

	dir = 1;
	if (game->keys->a)
		dir = -1;
	old.x = game->player->plane.x;
	old.y = game->player->plane.y;
	new.x = game->player->pos.x + (dir * old.x * slideSpeed);
	new.y = game->player->pos.y + (dir * old.y * slideSpeed);
// Collision management
	if (ft_ischarset(game->conf->map[(int)(new.y)][(int)(game->player->pos.x)],
		COLLISIONS))
		game->player->pos.y = new.y;
	if (ft_ischarset(game->conf->map[(int)(game->player->pos.y)][(int)(new.x)],
		COLLISIONS))
		game->player->pos.x = new.x;
}

/*Manage rotation movements*/
static void	rotate(t_game *game)
{
	int		dir;
	float	old_dir_x;
	float	old_plane_x;

	dir = 1;
	if (game->keys->left)
		dir *= -1;
	old_dir_x = game->player->dir.x;
	old_plane_x = game->player->plane.x;
	game->player->dir.x = old_dir_x
		* cos(dir * rotSpeed) - game->player->dir.y * sin(dir * rotSpeed);
	game->player->dir.y = old_dir_x
		* sin(dir * rotSpeed) + game->player->dir.y * cos(dir * rotSpeed);
	game->player->plane.x = old_plane_x
		* cos(dir * rotSpeed) - game->player->plane.y * sin(dir * rotSpeed);
	game->player->plane.y = old_plane_x
		* sin(dir * rotSpeed) + game->player->plane.y * cos(dir * rotSpeed);
}

int	event(t_game *game)
{
	if (game->keys->esc)
	{
		mlx_loop_end(game->win->mlx);
		return (0);
	}
	if (game->keys->w || game->keys->s)
		walk(game);
	if (game->keys->a || game->keys->d)
		slide(game);
	if (game->keys->left || game->keys->right)
		rotate(game);
	return (0);
}