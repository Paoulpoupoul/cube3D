/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:19:50 by jmorvan           #+#    #+#             */
/*   Updated: 2024/01/11 12:33:42 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_map(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (cub->conf.map[j])
	{
		i = -1;
		while (cub->conf.map[j][++i])
		{
			if (cub->conf.map[j][i] == '0')
			{
				if (!i || !j || i == cub->map_s.x - 1 || j == cub->map_s.y - 1)
					return (err_msg("map not close\n"));
				if (cub->conf.map[j][i + 1] == '2'
					|| cub->conf.map[j][i - 1] == '2'
					|| cub->conf.map[j + 1][i] == '2'
					|| cub->conf.map[j - 1][i] == '2')
					return (err_msg("map not close\n"));
			}
		}
		j++;
	}
	return (0);
}

int	check_parsing(t_cub *cub, int i)
{
	if (cub->conf.c.r < 0)
		return (err_msg("missing celling color in map file\n"));
	if (cub->conf.f.r < 0)
		return (err_msg("missing floor color in map file\n"));
	if (!cub->conf.ea.path || !cub->conf.no.path
		|| !cub->conf.so.path || !cub->conf.we.path)
		return (err_msg("missing texture in map file\n"));
	if (!i && !cub->conf.map)
		return (err_msg("missing map in map file\n"));
	return (0);
}

int	check_line(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != '\n')
		return (err_msg("misconfiguration in map file\n"));
	return (0);
}

int	add_color_to(char *line, int *i, int *color)
{
	int	l;

	l = 0;
	(*color) = 0;
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i) += 1;
	if (line[*i] == '+')
		i++;
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
	{
		(*color) = (*color) * 10 + line[*i] - '0';
		(*i) += 1;
		l++;
	}
	if (l > 4 || (*color) > 255)
		return (err_msg("RGB value needed between 0 and 255\n"));
	return (0);
}

int	check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	while (i > 0 && file[i] != '.')
		i--;
	if (!i)
		return (err_msg("texture file is not a .xpm\n"));
	if (ft_strncmp(".xpm\0", file + i, 5))
		return (err_msg("texture file is not a .xpm\n"));
	i = open(file, O_RDWR);
	if (i < 0)
	{
		if (errno == EACCES)
			return (err_msg("permission to texture file denied\n"));
		if (errno == EISDIR)
			return (err_msg("texture file is a directory\n"));
		return (err_msg("texture file not found\n"));
	}
	close(i);
	return (0);
}
