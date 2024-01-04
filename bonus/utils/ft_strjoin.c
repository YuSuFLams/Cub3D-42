/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:33:30 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:58:52 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			exit(EXIT_FAILURE);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), s2);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!str)
		exit (EXIT_FAILURE);
	i = -1;
	while (*(s1 + (++i)))
		*(str + i) = *(s1 + i);
	j = -1;
	while (*(s2 + (++j)))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	return (free(s1), str);
}
