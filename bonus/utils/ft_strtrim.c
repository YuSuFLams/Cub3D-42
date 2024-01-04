/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:18:41 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 15:59:18 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	test_char(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && test_char(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && s1[j - 1] && test_char(set, s1[j - 1]))
		j--;
	str = (char *)malloc(j - i + 1 * sizeof(char));
	if (!str)
		exit(EXIT_FAILURE);
	ft_strlcpy(str, &s1[i], j - i + 1);
	return (str);
}
