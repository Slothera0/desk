/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:00:14 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 20:20:56 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	quoted_word(char *str, size_t *j, t_tokens **tokens,
						t_minishell *minishell)
{
	size_t	temp;

	temp = *j;
	if (quote_handler(str, j))
	{
		(*j)++;
		while (str[*j] && !is_space(str[*j]))
		{
			quote_handler(str, j);
			(*j)++;
		}
		(*tokens) = create_tokens_node(tokens, WORD, minishell);
		if (!(*tokens))
			return (-1);
		(*tokens)->str = ft_substr(str, temp, *j - temp + 1);
		if (!(*tokens)->str)
			if (ft_perror("minishell: malloc", minishell, 1))
				return (-1);
		if (!str[*j])
			return (1);
		while (is_space(str[*j]))
			(*j)++;
	}
	return (0);
}

static int	if_greater(char *str, size_t *i, t_tokens **tokens,
						t_minishell *minishell)
{
	if (str[*i + 1] == GREATER)
	{
		(*tokens) = create_tokens_node(tokens, GREAT_GREAT, minishell);
		(*i)++;
	}
	else
		(*tokens) = create_tokens_node(tokens, GREAT, minishell);
	if (!(*tokens))
		return (-1);
	if (check_before((*tokens), minishell))
		return (-1);
	if (!str[*i + 1])
		if (parse_error("minishell: syntax error near unexpected"
				" token `newline'\n", minishell, 2))
			return (-1);
	return (0);
}

static int	if_lesser(char *str, size_t *i, t_tokens **tokens,
						t_minishell *minishell)
{
	if (str[*i + 1] == LESSER)
	{
		(*tokens) = create_tokens_node(tokens, LESS_LESS, minishell);
		(*i)++;
	}
	else
		(*tokens) = create_tokens_node(tokens, LESS, minishell);
	if (!(*tokens))
		return (-1);
	if (check_before((*tokens), minishell))
		return (-1);
	if (!str[*i + 1])
		if (parse_error("minishell: syntax error"
				" near unexpected token `newline'\n",
				minishell, 2))
			return (-1);
	return (0);
}

static int	if_word(char *str, size_t *i, t_tokens **tokens,
					t_minishell *minishell)
{
	size_t	temp;

	temp = *i;
	while (str[*i] && !is_token(str[*i]))
	{
		quote_handler(str, i);
		(*i)++;
		if (str[*i] == ' ')
			break ;
	}
	(*tokens) = create_tokens_node(tokens, WORD, minishell);
	if (!(*tokens))
		return (-1);
	(*tokens)->str = ft_substr(str, temp, *i - temp);
	if (!(*tokens)->str)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (-1);
	}
	return (0);
}

int	token_getter(char *split, size_t *j, t_tokens **tokens,
					t_minishell *minishell)
{
	int	quoted;

	quoted = quoted_word(split, j, tokens, minishell);
	if (quoted == -1)
		return (-1);
	else if (quoted)
		return (0);
	if (split[*j] == GREATER)
	{
		if (if_greater(split, j, tokens, minishell) == -1)
			return (-1);
		(*j)++;
	}
	else if (split[*j] == LESSER)
	{
		if (if_lesser(split, j, tokens, minishell) == -1)
			return (-1);
		(*j)++;
	}
	else if (split[*j] != SQUOTE && split[*j] != DQUOTE)
		if (if_word(split, j, tokens, minishell) == -1)
			return (-1);
	return (0);
}
