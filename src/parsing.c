/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:21:19 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/07 15:51:11 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	add_rgb(t_cub *cub, char *line, t_rgb *img)
{

}

int	add_texture(t_cub *cub, char *line, void *img)
{
	
}

int	read_line(t_cub *cub, char *line)
{
	if (!strncmp("SO ", line, 3) || strncmp("SO\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.so));
	if (!strncmp("NO ", line, 3) || strncmp("NO\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.no));
	if (!strncmp("EA ", line, 3) || strncmp("EA\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.ea));
	if (!strncmp("WE ", line, 3) || strncmp("WE\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.we));
	if (!strncmp("C ", line, 2) || strncmp("C\t", line, 2))
		return (add_rgb(cub, line + 1, &cub->txtr.cl));
	if (!strncmp("F ", line, 2) || strncmp("F\t", line, 2))
		return (add_rgb(cub, line + 1, &cub->txtr.fl));
	return (1);
}

int	read_file(t_cub *cub)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(cub->fd);
	if (!line)
		return (err_msg("map file empty\n"));
	while (line)
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] && line[i] != '\n')
		{
			if (read_line(cub, line + i))
				return (ft_free(line) + 1);
		}
		free(line);
		line = get_next_line(cub->fd);
	}
	return (0);
}

int	parsing(t_cub *cub, char *file)
{
	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		return (errno_msg("open", errno));
	if (read_file(cub))
	{
		get_next_line(-1);
		close(cub->fd);
		return (1);
	}
	get_next_line(-1);
	close(cub->fd);
	return (0);
}
