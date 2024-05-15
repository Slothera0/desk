/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:37:10 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/13 09:18:17 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s1;
	while (str[i] && is_set(str[i], set))
	{
		i++;
		if (str[i] && !is_set(str[i], set))
			return (i);
	}
	return (0);
}

static size_t	ft_len(char const *s1, char const *set, size_t start)
{
	size_t	index;
	char	*str;

	index = ft_strlen(s1) - 1;
	str = (char *) s1;
	while (index > 0 && is_set(str[index], set))
		index--;
	if (index == 0)
		return (0);
	return ((index + 1) - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		len;
	char		*trim;

	start = ft_start(s1, set);
	len = ft_len(s1, set, start);
	trim = ft_substr(s1, start, len);
	if (!trim)
		return (NULL);
	return (trim);
}
