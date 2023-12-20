/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:21:19 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/20 15:22:12 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	add_rgb(char *line, t_rgb *img)
{
	int	i;

	if (img->r >= 0)
		return (err_msg("too many identifier in map file\n"));
	i = 0;
	if (add_color_to(line, &i, &img->r))
		return (1);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != ',')
		return (err_msg("misconfiguration in map file\n"));
	i++;
	if (add_color_to(line, &i, &img->g))
		return (1);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != ',')
		return (err_msg("misconfiguration in map file\n"));
	i++;
	if (add_color_to(line, &i, &img->b))
		return (1);
	printf("color : r%d g%d b%d\n", img->r, img->g, img->b);
	return (check_line(line, i));
}

int	add_texture(t_cub *cub, char *line, void *img)
{
	char	*file;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (img)
		return (err_msg("too many identifier in map file\n"));
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i] || line[i] == '\n')
		return (err_msg("texture file name not found\n"));
	while (line[i + l] && line[i + l] != ' '
		&& line[i + l] != '\t' && line[i + l] != '\n')
		l++;
	file = malloc(sizeof(char) * (l + 1));
	if (!file)
		return (err_msg("malloc error\n"));
	ft_memcpy(file, line + i, l);
	file[l] = '\0';
	if (check_file(file))
		return (ft_free(file) + 1);
	if (add_texture_to_mlx(cub, file, img))
		return (ft_free(file) + 1);
	return (ft_free(file) + check_line(line, i + l));
}

int	read_line(t_cub *cub, char *line)
{
	if (!ft_strncmp("SO ", line, 3) || !ft_strncmp("SO\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.so));
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("NO\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.no));
	if (!ft_strncmp("EA ", line, 3) || !ft_strncmp("EA\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.ea));
	if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("WE\t", line, 3))
		return (add_texture(cub, line + 2, cub->txtr.we));
	if (!ft_strncmp("C ", line, 2) || !ft_strncmp("C\t", line, 2))
		return (add_rgb(line + 1, &cub->txtr.cl));
	if (!ft_strncmp("F ", line, 2) || !ft_strncmp("F\t", line, 2))
		return (add_rgb(line + 1, &cub->txtr.fl));
	return (2);
}

int	read_file(t_cub *cub)
{
	char	*line;
	int		i;
	int		j;

	line = get_next_line(cub->fd);
	if (!line)
		return (err_msg("map file empty\n"));
	while (line)
	{
		i = 0;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] && line[i] != '\n')
		{
			j = read_line(cub, line + i);
			if (j == 1)
				return (ft_free(line) + 1);
			else if (j > 1)
				return (parsing_map(cub, line));
		}
		free(line);
		line = get_next_line(cub->fd);
	}
	return (0);
}

int	parsing(t_cub *cub, char *file)
{
	ft_memset(&cub->txtr.cl, -1, sizeof(cub->txtr.cl));
	ft_memset(&cub->txtr.fl, -1, sizeof(cub->txtr.cl));
	ft_memset(&cub->pl_pos, -1, sizeof(cub->pl_pos));
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
	if (check_parsing(cub, 0))
		return (1);
	return (0);
}
