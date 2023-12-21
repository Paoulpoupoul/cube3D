/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:44:33 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/21 14:55:58 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	add_player_cord(t_cub *cub, int x, int y, char c)
{
	if (cub->player.pos.x > -1)
		return (err_msg("too many start position\n"));
	cub->player.pos.x = (float)x + 0.49f;
	cub->player.pos.y = (float)y + 0.49f;
	if (c == 'N')
	{
		cub->player.dir.x = 0.0f;
		cub->player.dir.y = -1.0f;;
	}
	else if (c == 'S')
	{
		cub->player.dir.x = 0.0f;
		cub->player.dir.y = -1.0f;;
	}
	else if (c == 'W')
	{
		cub->player.dir.x = 0.0f;
		cub->player.dir.y = -1.0f;
	}
	else
	{
		cub->player.dir.x = 0.0f;
		cub->player.dir.y = -1.0f;;
	}
	return (0);
}

char	char_to_map(char c)
{
	if (c == ' ' || c == '\n')
		return ('2');
	else if (c == '0')
		return ('0');
	else if (c == '1')
		return ('1');
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return ('0');
	return ('3');
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
