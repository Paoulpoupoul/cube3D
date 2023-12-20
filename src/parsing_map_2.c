/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:44:33 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/20 15:40:23 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_map(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (cub->map[j] && j < cub->map_s.y)
	{
		i = -1;
		while (++i < cub->map_s.x)
		{
			if (!cub->map[j][i])
			{
				if (!i || !j || i == cub->map_s.x - 1 || j == cub->map_s.y - 1)
					return (err_msg("map not close\n"));
				if (cub->map[j][i + 1] == 2 || cub->map[j][i - 1] == 2
					|| cub->map[j + 1][i] == 2 || cub->map[j - 1][i] == 2)
					return (err_msg("map not close\n"));
			}
		}
		j++;
	}
	return (0);
}

int	add_player_cord(t_cub *cub, int x, int y, char c)
{
	if (cub->pl_pos.x > -1)
		return (err_msg("too many start position\n"));
	cub->pl_pos.x = x;
	cub->pl_pos.y = y;
	// gerer l'angle de vue du joueur
	(void)c;
	return (0);
}

int	char_to_map(char c)
{
	if (c == ' ' || c == '\n')
		return (2);
	else if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (3);
}

int	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	rest_empty(char **map, int j)
{
	while (map[j])
	{
		if (line_empty(map[j]))
			return (1);
		j++;
	}
	return (0);
}
