/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:31:48 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 16:05:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (start > (int)ft_strlen(s))
		start = ft_strlen(s);
	if (len > (int)ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		exit (EXIT_FAILURE);
	i = -1;
	while (++i < len && s[i + start] && start < (int)ft_strlen(s))
		*(str + i) = *(s + (i + start));
	*(str + i) = '\0';
	return (str);
}
