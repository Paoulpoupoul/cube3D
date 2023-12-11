/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:19:50 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/11 20:39:07 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

int	add_texture_to_mlx(t_cub *cub, char *file, void *img)
{
	(void)cub;
	(void)file;
	(void)img;
	return (0);
}

int	check_file(char *file)
{
	int	i;

	printf("texture file name : %s\n", file);
	i = ft_strlen(file);
	while (i > 0 && file[i] != '.')
		i--;
	if (!i)
		return (err_msg("map file is not a .xpm\n"));
	if (ft_strncmp(".xpm\0", file + i, 5))
		return (err_msg("map file is not a .xpm\n"));
	i = open(file, O_RDWR);
	if (i < 0)
	{
		if (errno == EACCES)
			return (err_msg("permission to map file denied\n"));
		if (errno == EISDIR)
			return (err_msg("map file is a directory\n"));
		return (err_msg("map file not found\n"));
	}
	close(i);
	return (0);
}
