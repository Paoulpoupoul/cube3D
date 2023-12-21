/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:59:26 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_rayDir(t_game *game, int i, t_ray	*ray)
{
	float	cam_x;

	cam_x = 2 * i / (float)WIN_W - 1.0f;
	ray->rayDir.x = game->player->dir.x + game->player->plane.x * cam_x;
	ray->rayDir.y = game->player->dir.y + game->player->plane.y * cam_x;
}

static void	set_deltaDist(t_ray *ray)
{
	if (ray->rayDir.x != 0.0f)
		ray->deltaDist.x = f_abs(1 / ray->rayDir.x);
	else
		ray->deltaDist.x = FLT_MAX;
	if (ray->rayDir.y != 0.0f)
		ray->deltaDist.y = f_abs(1 / ray->rayDir.y);
	else
		ray->deltaDist.y = FLT_MAX;
}

static void	set_sideDist(t_game *game, t_ray *ray)
{
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (game->player->pos.x - ray->map.x) * ray->deltaDist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = (ray->map.x + 1.0f - game->player->pos.x)
			* ray->deltaDist.x;
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (game->player->pos.y - ray->map.y) * ray->deltaDist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = (ray->map.y + 1.0f - game->player->pos.y)
			* ray->deltaDist.y;
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
	set_rayDir(game, i, ray);
	set_map(game->player, ray);
	set_deltaDist(ray);
	set_sideDist(game, ray);
}
