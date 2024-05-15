/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:52:42 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 19:54:20 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*tokens_checker(char **split, t_minishell *minishell)
{
	size_t		i;
	t_tokens	*tokens;
	t_tokens	*start;

	i = 0;
	tokens = create_tokens_node(NULL, EMPTY, minishell);
	start = tokens;
	while (split[i])
	{
		if (tokens_checker_utils(split, i, &tokens, minishell) == -1)
			return (free_tokens(start));
		i++;
		if (split[i])
		{
			tokens = create_tokens_node(&tokens, T_PIPE, minishell);
			if (!tokens)
				return (free_tokens(start));
		}
	}
	if (get_redirections(&tokens, minishell) == -1)
		return (free_tokens(start));
	clean_tokens(&tokens);
	return (tokens);
}
