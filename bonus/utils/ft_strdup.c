/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:33:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:56:44 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s) + 1 * sizeof(char ));
	if (!str)
		exit(1);
	i = -1;
	while (*(s + (++i)))
		*(str + i) = *(s + i);
	str[i] = '\0';
	return (str);
}
