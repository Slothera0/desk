/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:24:12 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 19:54:50 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	remove_tabs(t_cmds **cmds, t_minishell *minishell)
{
	t_cmds	*start;
	size_t	i;

	i = 0;
	start = (*cmds);
	while (start)
	{
		while (start->args && start->args[i])
		{
			start->args = pro_expand(start->args, &i, minishell);
			if (!start->args)
				return (cmds_error(cmds), -1);
			i++;
		}
		start = start->next;
	}
	return (0);
}

int	parsing(char *line, t_minishell *minishell)
{
	char		**split;
	t_tokens	*tokens;

	split = pipes_split(line, minishell);
	if (!split)
		return (-1);
	tokens = tokens_checker(split, minishell);
	free_ptr_tab(split);
	if (!tokens)
		return (-1);
	while (tokens->previous != NULL)
		tokens = tokens->previous;
	minishell->cmds = create_cmds(&tokens, minishell);
	free_tokens(tokens);
	if (!minishell->cmds)
		return (-1);
	if (remove_tabs(&minishell->cmds, minishell))
		return (-1);
	return (0);
}
