/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:35:33 by lkoletzk          #+#    #+#             */
/*   Updated: 2024/01/11 15:28:16 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	set_side(t_ray *ray, int dir)
{
	if (!dir)
	{
		if (ray->raydir.x > 0)
			return (EA);
		return (WE);
	}
	else
	{
		if (ray->raydir.y < 0)
			return (SO);
		return (NO);
	}
}

static int	hit_loop(t_game *game, t_ray *ray)
{
	int	hit;
	int	ret;

	hit = 0;
	while (!hit)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ret = set_side(ray, 0);
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
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
	float	perpwalldist;
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
			perpwalldist = (ray.sidedist.x - ray.deltadist.x);
		else
			perpwalldist = (ray.sidedist.y - ray.deltadist.y);
		draw(game, perpwalldist, side);
		i++;
	}
	game->ray = NULL;
	if (game->win->win != NULL)
		mlx_put_image_to_window(game->win->mlx,
			game->win->win, game->win->img.img, 0, 0);
	return (0);
}

float	f_abs(float f)
{
	if (f < 0)
		f *= -1;
	return (f);
}
