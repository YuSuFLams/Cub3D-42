/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:33:56 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/08 22:39:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_putstr_fd(char *s, int fd, char *color)
{
	if (!s)
		ft_putstr_fd("(null)", fd, NULL);
	else
	{
		if (color)
			ft_putstr_fd(color, fd, NULL);
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}
