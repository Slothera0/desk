/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:01:54 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 16:53:53 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**first_arg(t_tokens *tokens, t_minishell *minishell, ssize_t *i)
{
	char	**args;

	(*i) = 0;
	args = ft_calloc(count_args(tokens) + 1, sizeof(char *));
	if (!args)
		if (ft_perror(MALLOC_ERR, minishell, 1))
			return (NULL);
	return (args);
}

static int	if_pipe(ssize_t *i, t_cmds **cmds, t_minishell *minishell,
					t_tokens *tokens)
{
	if (tokens->token == T_PIPE)
	{
		(*i) = 0;
		(*cmds)->next = create_node(minishell);
		if (!(*cmds)->next)
			return (-1);
		(*cmds) = (*cmds)->next;
	}
	return (0);
}

static int	if_word(ssize_t *i, t_cmds **cmds, t_tokens *tokens,
					t_minishell *minishell)
{
	if (tokens->token == WORD)
	{
		if (*i == 0)
		{
			(*cmds)->args = first_arg(tokens, minishell, i);
			if (!(*cmds)->args)
				return (-1);
		}
		(*cmds)->args[*i] = expander(tokens->str, minishell, false);
		if (!(*cmds)->args[(*i)++])
			return (-1);
	}
	return (0);
}

t_cmds	*create_cmds(t_tokens **tokens,	t_minishell *minishell)
{
	t_cmds	*cmds;
	t_cmds	*start;
	ssize_t	i;

	i = 0;
	cmds = create_node(minishell);
	if (!cmds)
		return (NULL);
	start = cmds;
	while (tokens)
	{
		if (if_word(&i, &cmds, (*tokens), minishell) == -1)
			if (cmds_error(&start))
				return (NULL);
		if (redirs_handler(&start, &cmds, tokens, minishell) == -1)
			return (NULL);
		if (if_pipe(&i, &cmds, minishell, (*tokens)))
			if (cmds_error(&start))
				return (NULL);
		if (!(*tokens)->next)
			break ;
		(*tokens) = (*tokens)->next;
	}
	return (start);
}
