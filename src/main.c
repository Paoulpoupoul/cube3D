/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:08 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 15:58:01 by jmorvan          ###   ########.fr       */
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

// On met toutes les structures (textures, colors, img) à NULL
	conf = init_map_cfg();

// On crée la map à la mano ...
	conf.map = calloc(15, sizeof(char*));
	conf.map[0] =  "        1111111111111111111111111";
	conf.map[1] =  "        1000000000110000000000001";
	conf.map[2] =  "        1011000001110000000000001";
	conf.map[3] =  "        1001000000000000000000001";
	conf.map[4] =  "111111111011000001110000000000001";
	conf.map[5] =  "10000000001100000111011111111111";
	conf.map[6] =  "11110111111111011100000000001";
	conf.map[7] =  "11110111111111011101010010001";
	conf.map[8] =  "11000000110101011100000010001";
	conf.map[9] =  "10000000000000001100000010001";
	conf.map[10] = "10000000000000001101010010001";
	conf.map[11] = "11000001110101011111011110N0111";
	conf.map[12] = "11110111 1110101 101111010001";
	conf.map[13] = "11111111 1111111 111111111111";
	conf.map[14] = NULL;
// On affiche la map pour vérifier qu'on est pas couillon ...
	for (int i = 0; conf.map[i]; i++)
		printf("%s\n", conf.map[i]);	

// On configure notre personnage à la mano ...
// Direction SO
	player.pos.x = (float)26 + 0.49f;
	player.pos.y = (float)11 + 0.49f;
	player.dir.x = 0.0f;
	player.dir.y = -1.0f;
	player.plane.x = FOV;
	player.plane.y = 0.0f;

	cub3d(&conf, &player);
	free(conf.map);
	// free_conf(conf);
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
	init_map_cfg(&cub.conf, &cub.player);
	cub3d(&cub.conf, &cub.player);
	return (quit(&cub));
}
