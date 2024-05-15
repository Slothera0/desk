/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:44:32 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/10 13:20:02 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	total_len;

	total_len = 0;
	if (ft_strlen(s) < 1 || start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	while (total_len < len && s[total_len + start])
		total_len++;
	new = ft_calloc(total_len + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
