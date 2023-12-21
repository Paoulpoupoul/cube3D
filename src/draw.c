/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:13:49 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/21 15:59:55 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_text_x(t_game *game, t_texture text, float dist, int side)
{
	float	wall_x;
	int		ret;

	if (side > 1)
		wall_x = game->player->pos.y + dist * game->ray->raydir.y;
	else
		wall_x = game->player->pos.x + dist * game->ray->raydir.x;
	wall_x -= floorf((wall_x));
	ret = (int)(wall_x * text.width);
	if (side == SO || side == WE)
		ret = text.width - ret - 1;
	return (ret);
}

static void	wall(t_game *game, t_texture text, float dist, int height)
{
	int		text_x;
	int		text_y;
	float	step;
	float	text_pos;
	int		y;

	text_x = get_text_x(game, text, dist, text.side);
	step = 1.0f * text.height / height;
	y = draw_start(height);
	text_pos = (y - (WIN_H >> 1) + (height >> 1)) * step;
	while (y < draw_end(height))
	{
		text_y = (int)text_pos & (text.height - 1);
		if (game->win->win != NULL)
			img_pix_put(&game->win->img, game->ray->line, y,
				get_pix_color(&text.img, text_x, text_y));
		text_pos += step;
		y++;
	}
}

static void	draw_wall(t_game *game, float dist, int side, int height)
{
	if (side == NO)
		wall(game, game->conf->no, dist, height);
	if (side == SO)
		wall(game, game->conf->so, dist, height);
	if (side == EA)
		wall(game, game->conf->ea, dist, height);
	if (side == WE)
		wall(game, game->conf->we, dist, height);
}

void	draw(t_game *game, float dist, int side)
{
	int	height;
	int	y;

	height = (int)(WIN_H / dist);
	y = 0;
	while (y < draw_start(height))
		img_pix_put(&game->win->img, game->ray->line, y++, game->conf->c.color);
	draw_wall(game, dist, side, height);
	y = draw_end(height);
	while (y < WIN_H)
		img_pix_put(&game->win->img, game->ray->line, y++, game->conf->f.color);
}
