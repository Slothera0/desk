/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:15:02 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/23 11:25:54 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmds_error(t_cmds **cmds)
{
	t_cmds	*temp;

	while ((*cmds))
	{
		if ((*cmds)->infile != -1)
			close((*cmds)->infile);
		if ((*cmds)->outfile != -1)
			close((*cmds)->outfile);
		if ((*cmds)->args)
			free_ptr_tab((*cmds)->args);
		temp = (*cmds);
		(*cmds) = (*cmds)->next;
		free(temp);
	}
	return (1);
}

t_cmds	*create_node(t_minishell *minishell)
{
	t_cmds	*new;

	new = malloc(sizeof(t_cmds));
	if (!new)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	new->next = NULL;
	new->args = NULL;
	new->path = NULL;
	new->infile = -1;
	new->outfile = -1;
	return (new);
}

size_t	count_args(t_tokens *tokens)
{
	size_t	count;

	count = 0;
	while (tokens && tokens->token != T_PIPE)
	{
		if (tokens->token == WORD)
			count++;
		tokens = tokens->next;
	}
	return (count);
}
