/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:37:46 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 14:05:42 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	if_redirection(t_cmds **cmds, t_tokens **tokens,
							t_minishell *minishell)
{
	int	get_return;

	get_return = 0;
	if ((*tokens)->token == INPUT)
		get_return = input(cmds, (*tokens), minishell);
	if ((*tokens)->token == OUTPUT)
		get_return = output(cmds, (*tokens), minishell);
	if ((*tokens)->token == APPEND)
		get_return = append(cmds, (*tokens), minishell);
	if ((*tokens)->token == HEREDOC)
		get_return = heredoc_redir(cmds, tokens, minishell);
	if (get_return == -1)
		return (-1);
	else if (get_return == 1)
		return (1);
	return (0);
}

int	redirs_handler(t_cmds **start, t_cmds **cmds, t_tokens **tokens,
					t_minishell *minishell)
{
	int	redir_return;

	redir_return = if_redirection(cmds, tokens, minishell);
	if (redir_return == -1)
		if (cmds_error(start))
			return (-1);
	if (redir_return == 1)
		if (skip_pipe(tokens, cmds) == -1)
			if (cmds_error(start))
				return (-1);
	return (0);
}
