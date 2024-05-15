/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:09:31 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 14:49:42 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quotes_remover(char *str, size_t first, size_t *last,
						t_minishell *minishell)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = ft_calloc(ft_strlen(str) - 1, sizeof(char));
	if (!new)
		return (ft_perror(MALLOC_ERR, minishell, 1), NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (j == first)
			j++;
		if (j == *last)
		{
			*last = i;
			if (str[++j] == ' ')
				break ;
		}
		new[i++] = str[j];
		if (!str[j++])
			break ;
	}
	free(str);
	return (new);
}

char	*var_remover(char *str, size_t start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = ft_calloc(ft_strlen(str) - len, sizeof(char));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str[j])
	{
		if (j == start)
			while (j - i != len + 1)
				j++;
		new[i++] = str[j];
		if (!str[j++])
			break ;
	}
	free(str);
	return (new);
}
