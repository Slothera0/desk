/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_stop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:21:17 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/08 03:50:31 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_stop(const char *s, char c, int keep_last)
{
	size_t	i;
	size_t	len;
	char	*copy;

	len = 0;
	if (!s || !s[0])
		return (NULL);
	while (s[len] && s[len] != c)
		len++;
	if (s[len] == c && keep_last == 1)
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	if (s[i] == c && keep_last == 1)
		copy[i++] = c;
	copy[i] = '\0';
	return (copy);
}
