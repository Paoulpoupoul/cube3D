/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:37 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/20 14:33:42 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./cub3D map.cub

int	quit(t_cub *cub)
{
	if (cub->c_map)
		free_tabc(cub->c_map);
	if (cub->map)
		free_tab(cub->map, cub->map_s.y);
	return (0);
}

int	check_file_name(char *file)
{
	int	i;

	i = ft_strlen(file);
	while (i > 0 && file[i] != '.')
		i--;
	if (!i)
		return (err_msg("map file is not a .cub\n"));
	if (ft_strncmp(".cub\0", file + i, 5))
		return (err_msg("map file is not a .cub\n"));
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

int	main(int ac, char **av, char **env)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(cub));
	(void)env;
	if (ac < 2)
		return (err_msg("a map file is needed\n"));
	else if (ac > 2)
		return (err_msg("too many arguments\n"));
	if (check_file_name(av[1]))
		return (1);
	printf("map file found !\n");
	if (parsing(&cub, av[1]))
		return (quit(&cub) + 1);
	return (quit(&cub));
}
