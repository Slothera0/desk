/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:43 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/08 03:21:05 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*suppr_current_line(char *str, char **buffer)
{
	char		*dst;
	size_t		i;
	int long	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (i == ft_strlen(str))
		(*buffer) = NULL;
	if (i == ft_strlen(str))
		return (double_free(str, NULL));
	dst = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dst)
	{
		(*buffer) = NULL;
		return (double_free(str, NULL));
	}
	j = -1;
	while (str[i + (++j)])
		dst[j] = str[i + j];
	dst[j] = '\0';
	(*buffer) = dst;
	return (double_free(str, NULL), dst);
}

char	*double_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}
