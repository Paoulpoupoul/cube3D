/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:08 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 18:05:15 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*int	main(int argc, char **argv)
{
	(void)argv;
	t_map		conf;
	t_player	player;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	conf = init_map_cfg();
	conf.map = calloc(6, sizeof(char*));
	conf.map[0] =  "111111";
	conf.map[1] =  "1N0101";
	conf.map[2] =  "100001";
	conf.map[3] =  "110001";
	conf.map[4] =  "111111";
	conf.map[5] = NULL;
	for (int i = 0; conf.map[i]; i++)
		printf("%s\n", conf.map[i]);

	player.pos.x = (float)1 + 0.49f;
	player.pos.y = (float)1 + 0.49f;
	//----NO
	// player.dir.x = 0.0f;
	// player.dir.y = -1.0f;
	// player.plane.x = FOV;
	// player.plane.y = 0.0f;
	//----SO
	// player.dir.x = 0.0f;
	// player.dir.y = 1.0f;
	// player.plane.x = -FOV;
	// player.plane.y = 0.0f;
	//----EA
	// player.dir.x = 1.0f;
	// player.dir.y = 0.0f;
	// player.plane.x = 0.0f;
	// player.plane.y = FOV;
	//----WE
	player.dir.x = -1.0f;
	player.dir.y = 0.0f;
	player.plane.x = 0.0f;
	player.plane.y = -FOV;
	
	cub3d(&conf, &player);
	free(conf.map);
	return (0);
}*/

int	quit(t_cub *cub)
{
	if (cub->conf.tmp_map)
		free_tabc(cub->conf.tmp_map);
	if (cub->conf.map)
		free_tabc(cub->conf.map);
	if (cub->conf.no.path)
		free(cub->conf.no.path);
	if (cub->conf.so.path)
		free(cub->conf.so.path);
	if (cub->conf.ea.path)
		free(cub->conf.ea.path);
	if (cub->conf.we.path)
		free(cub->conf.we.path);
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

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(cub));
	if (ac < 2)
		return (err_msg("a map file is needed\n"));
	else if (ac > 2)
		return (err_msg("too many arguments\n"));
	if (check_file_name(av[1]))
		return (1);
	printf("map file found !\n");
	if (parsing(&cub, av[1]))
		return (quit(&cub) + 1);
	init_map_cfg(&cub.conf);
	cub3d(&cub.conf, &cub.player);
	return (quit(&cub));
}
