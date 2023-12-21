/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:49:42 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 11:46:26 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_conf(t_map conf)
{
	// if (conf.no.path)
	// 	free(conf.no.path);
	// if (conf.so.path)
	// 	free(conf.so.path);
	// if (conf.ea.path)
	// 	free(conf.ea.path);
	// if (conf.we.path)
	// 	free(conf.we.path);
	// if (conf.f.raw)
	// 	free(conf.f.raw);
	// if (conf.c.raw)
	// 	free(conf.c.raw);
	free_tabc(conf.map);
}
