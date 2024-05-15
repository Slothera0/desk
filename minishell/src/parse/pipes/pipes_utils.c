/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:41:36 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/22 17:35:28 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

char	*no_pipe_cmd(char *line, size_t *i, size_t start,
						t_minishell *minishell)
{
	char	*new;

	new = NULL;
	while (line[*i])
	{
		quote_handler(line, i);
		if (line[*i] == PIPE)
			break ;
		*i += 1;
	}
	new = ft_substr(line, start, *i - start);
	if (!new)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	(*i)++;
	return (new);
}

char	**init_pipes_split(char *line, int args, size_t *i,
							t_minishell *minishell)
{
	char	**split;

	split = ft_calloc(args + 2, sizeof(char *));
	if (!split)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	split[0] = no_pipe_cmd(line, i, 0, minishell);
	if (!split[0])
		return (NULL);
	return (split);
}
