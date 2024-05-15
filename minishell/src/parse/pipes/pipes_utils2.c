/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:37:52 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 16:37:52 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_split(char *line, int args, size_t *i,
							t_minishell *minishell)
{
	char	**split;

	if (args == -1)
		return (NULL);
	split = init_pipes_split(line, args, i, minishell);
	if (!split)
		return (NULL);
	return (split);
}

void	init_variables(int *args, size_t *delim, size_t *i,
							t_minishell *minishell)
{
	(*delim) = (*i);
	(*args) = 1;
	minishell->pipe = true;
	(*i)--;
}

char	*split_arg(char *line, size_t *delim, size_t i,
						t_minishell *minishell)
{
	char	*new;

	new = ft_substr(line, (*delim), i - (*delim));
	if (!new)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	(*delim) = i + 1;
	return (new);
}
