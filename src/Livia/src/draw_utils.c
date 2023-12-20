/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:16:29 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/12/20 17:48:31 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_pix_color(t_img *tex, int x, int y)
{
	char	*ret;

	ret = tex->addr + ((y * tex->line_len) + (x * (tex->bpp / 8)));
	return (*(int *)ret);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	draw_end(int height)
{
	int	i;

	i = (height >> 1) + (WIN_H >> 1);
	if (i >= WIN_H)
		i = WIN_H;
	return (i);
}

int	draw_start(int height)
{
	int	i;

	i = (-height >> 1) + (WIN_H >> 1);
	if (i < 0)
		i = 0;
	return (i);
}