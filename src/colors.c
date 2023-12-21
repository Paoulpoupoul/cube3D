/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:41 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 13:55:55 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*Setting up colors*/
void	set_colors(t_map *cfg)
{
	cfg->f.color = create_trgb(0, cfg->f.r, cfg->f.g, cfg->f.b);
	cfg->c.color = create_trgb(0, cfg->c.r, cfg->c.g, cfg->c.b);
}
