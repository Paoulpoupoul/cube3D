/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:58:04 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/20 15:59:13 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischarset(char c, char *charset)
{
	while (charset && *charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}
