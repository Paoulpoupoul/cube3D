/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:35:33 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/20 17:40:30 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	set_side(t_ray *ray, int dir)
{
	if (!dir)
	{
		if (ray->rayDir.x > 0)
			return (EA);
		return (WE);
	}
	else
	{
		if (ray->rayDir.y < 0)
			return (NO);
		return (SO);
	}
}

static int	hit_loop(t_game *game, t_ray *ray)
{
	int	hit;
	int	ret;

	hit = 0;
	while (!hit)
	{
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->map.x += ray->step.x;
			ret = set_side(ray, 0);
		}
		else
		{
			ray->sideDist.y += ray->deltaDist.y;
			ray->map.y += ray->step.y;
			ret = set_side(ray, 1);
		}
		if (game->conf->map[ray->map.y][ray->map.x] == '1')
			hit = 1;
	}
	return (ret);
}

int	raycasting(t_game *game)
{
	float	perpWallDist;
	int		side;
	t_ray	ray;
	int		i;

	ray = init_ray();
	i = 0;
	game->ray = &ray;
	event(game);
	while (i < WIN_W)
	{
		ray_update(game, i, &ray);
		side = hit_loop(game, &ray);
		if (side > 1)
			perpWallDist = (ray.sideDist.x - ray.deltaDist.x);
		else
			perpWallDist = (ray.sideDist.y - ray.deltaDist.y);
		draw(game, perpWallDist, side);
		i++;
	}
	game->ray = NULL;
	if (game->win->win != NULL)
		mlx_put_image_to_window(game->win->mlx,	game->win->win, game->win->img.img, 0, 0);
	return (0);
}