/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:20:45 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 19:56:33 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	expand_tokens(t_tokens **tokens, t_minishell *minishell)
{
	char	*temp;

	temp = ft_strdup((*tokens)->str);
	if (!temp)
		return (ft_perror(MALLOC_ERR, minishell, 1), -1);
	if ((*tokens)->previous->token == LESS)
	{
		(*tokens)->token = INPUT;
		(*tokens)->str = expander((*tokens)->str, minishell, false);
	}
	else if ((*tokens)->previous->token == GREAT)
	{
		(*tokens)->token = OUTPUT;
		(*tokens)->str = expander((*tokens)->str, minishell, false);
	}
	else if ((*tokens)->previous->token == GREAT_GREAT)
	{
		(*tokens)->token = APPEND;
		(*tokens)->str = expander((*tokens)->str, minishell, false);
	}
	else
		return (free(temp), 0);
	if (!(*tokens)->str)
		return (free(temp), -1);
	return (ambiguous_redirect(tokens, temp, minishell), 1);
}

int	get_redirections(t_tokens **tokens, t_minishell *minishell)
{
	int	expand;

	while ((*tokens)->previous != NULL)
		(*tokens) = (*tokens)->previous;
	while ((*tokens))
	{
		if ((*tokens)->token == WORD)
		{
			if ((*tokens)->previous)
			{
				expand = expand_tokens(tokens, minishell);
				if (expand == -1)
					return (-1);
				else if ((*tokens)->previous->token == LESS_LESS
					&& expand != 1)
					(*tokens)->token = HEREDOC;
			}
		}
		if (!(*tokens)->next)
			break ;
		(*tokens) = (*tokens)->next;
	}
	return (0);
}

int	tokens_checker_utils(char **split, size_t i, t_tokens **tokens,
						t_minishell *minishell)
{
	size_t	j;

	j = 0;
	while (split[i][j])
	{
		while (is_space(split[i][j]))
			j++;
		if (split[i][j])
			if (token_getter(split[i], &j, tokens, minishell) == -1)
				return (-1);
	}
	return (0);
}

t_tokens	*create_tokens_node(t_tokens **tokens, t_token token,
								t_minishell *minishell)
{
	t_tokens	*new;

	if (tokens && (*tokens)->token == EMPTY)
		(*tokens)->token = token;
	else
	{
		new = malloc(sizeof(t_tokens));
		if (!new)
		{
			ft_perror(MALLOC_ERR, minishell, 1);
			return (NULL);
		}
		new->str = NULL;
		if (tokens)
			new->previous = (*tokens);
		else
			new->previous = NULL;
		new->next = NULL;
		new->token = token;
		if (tokens && (*tokens))
			(*tokens)->next = new;
		return (new);
	}
	return (*tokens);
}

void	*free_tokens(t_tokens *tokens)
{
	t_tokens	*temp;

	while (tokens->previous)
		tokens = tokens->previous;
	while (tokens)
	{
		if (tokens->str)
			free(tokens->str);
		temp = tokens;
		tokens = tokens->next;
		free(temp);
	}
	return (NULL);
}
