/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:20:20 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/03/27 10:10:30 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
			len++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c)
			i++;
	}
	return (len);
}

static void	ft_fill(const char *s, char *str, int index, char c)
{
	size_t	i;

	i = 0;
	while (i + index < ft_strlen(s) && s[i + index] != c)
	{
		str[i] = s[i + index];
		i++;
	}
}

static char	**ft_free(char **str, size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	str = (char **) ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			str[j] = ft_calloc(ft_strlen_c(&s[i], c) + 1, sizeof(char));
			if (!str[j])
				return (ft_free(str, j));
			ft_fill(s, str[j], i, c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (str);
}
