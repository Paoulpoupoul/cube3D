/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:12:08 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/20 17:52:57 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
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
	conf.map = calloc(6, sizeof(char*));
	conf.map[0] = "111111";
	conf.map[1] = "1N0101";
	conf.map[2] = "100001";
	conf.map[3] = "110001";
	conf.map[4] = "111111";
	conf.map[5] = NULL;
// On affiche la map pour vérifier qu'on est pas couillon ...
	for (int i = 0; conf.map[i]; i++)
		printf("%s\n", conf.map[i]);	

// On configure notre personnage à la mano ...
	player.pos.x = (float)1 + 0.49f;
	player.pos.y = (float)1 + 0.49f;
	player.dir.x = 0.0f;
	player.dir.y = -1.0f;;
	player.plane.x = FOV;
	player.plane.y = 0.0f;

	cub3d(&conf, &player);
	// free_conf(conf);
	return (0);
}

