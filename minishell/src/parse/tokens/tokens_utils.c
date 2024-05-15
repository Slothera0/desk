/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:24:04 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/22 15:49:58 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_before(t_tokens *tokens, t_minishell *minishell)
{
	if (tokens->previous)
	{
		if (tokens->previous->token == LESS
			|| tokens->previous->token == LESS_LESS
			|| tokens->previous->token == GREAT
			|| tokens->previous->token == GREAT_GREAT)
		{
			if (tokens->token == LESS)
				parse_error("minishell: syntax error "
					"near unexpected token `<'\n", minishell, 2);
			if (tokens->token == LESS_LESS)
				parse_error("minishell: syntax error "
					"near unexpected token `<<'\n", minishell, 2);
			if (tokens->token == GREAT)
				parse_error("minishell: syntax error "
					"near unexpected token `>\n", minishell, 2);
			if (tokens->token == GREAT_GREAT)
				parse_error("minishell: syntax error "
					"near unexpected token `>>'\n", minishell, 2);
			return (true);
		}
		else
			return (false);
	}
	return (false);
}

static int	to_clean(t_tokens **tokens)
{
	t_tokens	*temp;

	if ((*tokens)->previous)
	{
		(*tokens)->previous->next = (*tokens)->next;
		(*tokens)->next->previous = (*tokens)->previous;
	}
	else
		(*tokens)->next->previous = NULL;
	if (!(*tokens)->next)
	{
		free(*tokens);
		return (1);
	}
	temp = (*tokens);
	(*tokens) = (*tokens)->next;
	free(temp);
	return (0);
}

void	clean_tokens(t_tokens **tokens)
{
	while ((*tokens)->previous != NULL)
		(*tokens) = (*tokens)->previous;
	while ((*tokens))
	{
		if ((*tokens)->token == LESS || (*tokens)->token == LESS_LESS
			|| (*tokens)->token == GREAT || (*tokens)->token == GREAT_GREAT)
		{
			if (to_clean(tokens))
				break ;
		}
		else
		{
			if (!(*tokens)->next)
				break ;
			(*tokens) = (*tokens)->next;
		}
	}
}
