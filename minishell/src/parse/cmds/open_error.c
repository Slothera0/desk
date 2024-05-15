/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:01:51 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 14:16:59 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_pipe(t_tokens **tokens, t_cmds **cmds)
{
	if ((*cmds)->args)
		free_ptr_tab((*cmds)->args);
	(*cmds)->args = NULL;
	while ((*tokens)->next && (*tokens)->next->token != T_PIPE)
		(*tokens) = (*tokens)->next;
	if (!(*tokens)->next)
		return (-1);
	(*tokens) = (*tokens)->next;
	return (0);
}

int	open_error(char *prefix, t_minishell *minishell)
{
	write(2, "minishell: open: ", 17);
	if (minishell->pipe)
	{
		perror(prefix);
		return (0);
	}
	else
		ft_perror(prefix, minishell, 1);
	return (-1);
}
