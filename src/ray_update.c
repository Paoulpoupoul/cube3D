/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:59:26 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 16:03:21 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_raydir(t_game *game, int i, t_ray *ray)
{
	float	cam_x;

	cam_x = 2 * i / (float)WIN_W - 1.0f;
	ray->raydir.x = game->player->dir.x + game->player->plane.x * cam_x;
	ray->raydir.y = game->player->dir.y + game->player->plane.y * cam_x;
}

static void	set_deltadist(t_ray *ray)
{
	if (ray->raydir.x != 0.0f)
		ray->deltadist.x = f_abs(1 / ray->raydir.x);
	else
		ray->deltadist.x = FLT_MAX;
	if (ray->raydir.y != 0.0f)
		ray->deltadist.y = f_abs(1 / ray->raydir.y);
	else
		ray->deltadist.y = FLT_MAX;
}

static void	set_sidedist(t_game *game, t_ray *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (game->player->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0f - game->player->pos.x)
			* ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (game->player->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0f - game->player->pos.y)
			* ray->deltadist.y;
	}
}

static void	set_map(t_player *player, t_ray *ray)
{
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
}

void	ray_update(t_game *game, int i, t_ray *ray)
{
	ray->line = i;
	set_raydir(game, i, ray);
	set_map(game->player, ray);
	set_deltadist(ray);
	set_sidedist(game, ray);
}
