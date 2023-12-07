/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorvan <jmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:37 by jmorvan           #+#    #+#             */
/*   Updated: 2023/12/07 14:24:30 by jmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
	t_cub cub;

	ft_memset(&cub, 0, sizeof(cub));
	(void)env;
	if (ac < 2)
		return (err_msg("a map file is needed\n"));
	else if (ac > 2)
		return (err_msg("too many arguments\n"));
	if (check_file_name(av[1]))
		return (1);
	if (parsing(&cub, av[1]))
		return (1);
	return (0);
}