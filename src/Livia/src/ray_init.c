/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:30:13 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/20 17:32:56 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* Raycasting initialisation */

static t_point	empty_point(void)
{
	t_point	point;

	point.x = 0.0f;
	point.y = 0.0f;
	return (point);
}

static t_coord	empty_coord(void)
{
	t_coord	coord;

	coord.x = 0;
	coord.y = 0;
	return (coord);
}

t_ray	init_ray(void)
{
	t_ray	ray;

	ray.rayDir = empty_point();
	ray.sideDist = empty_point();
	ray.deltaDist = empty_point();
	ray.map = empty_coord();
	ray.step = empty_coord();
	ray.line = 0;
	return (ray);
}