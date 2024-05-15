/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:19:04 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/23 14:04:41 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*quote_after_dollar(char *str, size_t index)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(str), sizeof(char));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		if (i == index)
			i++;
		new[j++] = str[i];
		i++;
	}
	free(str);
	return (new);
}

char	*pre_expand(char *str, t_minishell *minishell)
{
	size_t	i;
	char	*new;

	i = 0;
	new = ft_strdup(str);
	free(str);
	if (!new)
		if (ft_perror(MALLOC_ERR, minishell, 1))
			return (NULL);
	while (new[i])
	{
		if (new[i] == '$')
		{
			if (new[i + 1] == SQUOTE || new[i + 1] == DQUOTE)
			{
				new = quote_after_dollar(new, i);
				if (!new)
					if (ft_perror(MALLOC_ERR, minishell, 1))
						return (NULL);
				quote_handler(new, &i);
			}
		}
		i++;
	}
	return (new);
}
