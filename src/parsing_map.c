/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:53:19 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/21 18:03:19 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	print_map(char **tab)
// {
// 	int	j;
// 	j = 0;
// 	while (tab[j])
// 	{
// 		printf("%s\n", tab[j]);
// 		j++;
// 	}
// }

int	check_char_line(t_cub *cub, char *line, int j)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (err_msg("wrong character in the map\n"));
		if (line[i] != ' ' && i > cub->map_s.x)
			cub->map_s.x = i;
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			if (add_player_coord(cub, i, j, line[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	get_map_s(t_cub *cub)
{
	int	j;

	j = 0;
	while (cub->conf.tmp_map[j])
	{
		if (!line_empty(cub->conf.tmp_map[j]))
		{
			if (!rest_empty(cub->conf.tmp_map, j))
			{
				cub->map_s.x++;
				return (0);
			}
		}
		if (check_char_line(cub, cub->conf.tmp_map[j], j))
			return (1);
		cub->map_s.y++;
		j++;
	}
	cub->map_s.x++;
	return (0);
}

int	add_line_to_map(t_cub *cub, char *line)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = malloc(sizeof(char *) * (ft_tab_size(cub->conf.tmp_map) + 2));
	if (!tmp)
		return (err_msg("malloc error\n"));
	if (!cub->conf.tmp_map)
	{
		tmp[0] = line;
		tmp[1] = NULL;
		cub->conf.tmp_map = tmp;
		return (0);
	}
	while (cub->conf.tmp_map[++i])
		tmp[i] = cub->conf.tmp_map[i];
	tmp[i] = line;
	tmp[i + 1] = NULL;
	free(cub->conf.tmp_map);
	cub->conf.tmp_map = tmp;
	return (0);
}

int	create_map(t_cub *cub)
{
	int	j;
	int	i;

	j = -1;
	cub->conf.map = malloc(sizeof(char *) * (cub->map_s.y + 1));
	if (!cub->conf.map)
		return (err_msg("malloc error\n"));
	while (cub->conf.tmp_map[++j] && j < cub->map_s.y)
	{
		cub->conf.map[j] = malloc(sizeof(char) * (cub->map_s.x + 1));
		if (!cub->conf.map[j])
			return (err_msg("malloc error\n"));
		i = -1;
		while (cub->conf.tmp_map[j][++i] && i < cub->map_s.x)
			cub->conf.map[j][i] = char_to_map(cub->conf.tmp_map[j][i]);
		if (!cub->conf.tmp_map[j][i] && i < cub->map_s.x)
		{
			while (i < cub->map_s.x)
				cub->conf.map[j][i++] = '2';
		}
		cub->conf.map[j][i] = '\0';
	}
	cub->conf.map[j] = NULL;
	return (0);
}

int	parsing_map(t_cub *cub, char *line)
{
	if (check_parsing(cub, 1))
		return (1);
	while (line)
	{
		if (add_line_to_map(cub, line))
			return (ft_free(line) + 1);
		line = get_next_line(cub->fd);
	}
	if (get_map_s(cub))
		return (1);
	if (create_map(cub))
		return (1);
	if (check_map(cub))
		return (1);
	return (0);
}
