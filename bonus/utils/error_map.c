/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:49:11 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/08 14:39:20 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_map(int fd, int flag)
{
	if (flag == 1)
	{
		if (fd == -1)
			(perror("\033[91mopen"), exit(EXIT_FAILURE));
	}
	else
	{
		if (close(fd) != 0)
			(perror("\033[91mclose"), exit(EXIT_FAILURE));
	}
}
