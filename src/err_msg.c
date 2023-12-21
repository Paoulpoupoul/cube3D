/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:07:25 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/21 16:07:23 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	err_msg(char *msg)
{
	write(2, "Error\n", 6);
	if (!msg)
		return (1);
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	errno_msg(char *msg, int err)
{
	char	*str;

	write(2, "Error\n", 6);
	if (!msg)
		return (1);
	write(2, msg, ft_strlen(msg));
	str = strerror(err);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}
