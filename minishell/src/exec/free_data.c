/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:28:49 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 16:51:10 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_data(t_minishell *data)
{
	t_cmds	*current;
	t_cmds	*temp;

	current = data->cmds;
	while (current)
	{
		if (current->infile != -1)
		{
			close(current->infile);
			current->infile = -1;
		}
		if (current->outfile != -1)
		{
			close(current->outfile);
			current->outfile = -1;
		}
		if (current->args)
			ft_free_array(current->args);
		temp = current->next;
		free(current);
		current = temp;
	}
}

void	free_cmd(t_cmds *cmd)
{
	t_cmds	*temp;

	while (cmd)
	{
		if (cmd->infile != -1)
			close(cmd->infile);
		if (cmd->outfile != -1)
			close(cmd->outfile);
		if (cmd->args)
			ft_free_array(cmd->args);
		temp = cmd->next;
		free(cmd);
		cmd = temp;
	}
}
