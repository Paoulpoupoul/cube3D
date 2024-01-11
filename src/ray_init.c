/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:30:13 by lkoletzk          #+#    #+#             */
/*   Updated: 2024/01/11 11:57:36 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

	ray.raydir = empty_point();
	ray.sidedist = empty_point();
	ray.deltadist = empty_point();
	ray.map = empty_coord();
	ray.step = empty_coord();
	ray.line = 0;
	return (ray);
}
