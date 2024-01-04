/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:48:31 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/16 00:55:04 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file(t_cub3d *cub)
{
	int	fd;
	int	i;

	i = 0;
	while (i < 4)
	{
		fd = open(cub->direction[i], O_RDONLY);
		if (fd == -1)
			(ft_putstr_fd(ERR_PATH, 2, RED), exit(EXIT_FAILURE));
		close(fd);
		i++;
	}
}
