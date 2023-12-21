/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:02:21 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:00 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_point	get_player_pos(char **map)
{
	int		y;
	int		x;
	t_point	ret;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_ischarset(map[y][x], SPAWN))
			{
				ret.y = (float)y + 0.49f;
				ret.x = (float)x + 0.49f;
				map[y][x] = '0';
				break ;
			}
			x++;
		}
		y++;
	}
	return (ret);
}

t_point	get_plane_dir(t_map *conf)
{
	t_point	ret;

	ret.x = 0.0f;
	ret.y = 0.0f;
	if (conf->spawn_dir == 'W')
		ret.y = -FOV;
	else if (conf->spawn_dir == 'E')
		ret.y = FOV;
	else if (conf->spawn_dir == 'N')
		ret.x = FOV;
	else if (conf->spawn_dir == 'S')
		ret.x = -FOV;
	return (ret);
}

t_point	get_player_dir(t_map	*conf)
{
	t_point	ret;

	ret.x = 0.0f;
	ret.y = 0.0f;
	if (conf->spawn_dir == 'N')
		ret.y = -1.0f;
	else if (conf->spawn_dir == 'S')
		ret.y = 1.0f;
	else if (conf->spawn_dir == 'W')
		ret.x = -1.0f;
	else if (conf->spawn_dir == 'E')
		ret.x = 1.0f;
	return (ret);
}

float	f_abs(float f)
{
	if (f < 0)
		f *= -1;
	return (f);
}
