/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:27:20 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 15:06:19 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input(t_cmds **cmds, t_tokens *tokens, t_minishell *minishell)
{
	if ((*cmds)->infile != -1 && close((*cmds)->infile) == -1)
	{
		printf("minishell: close");
		perror(tokens->str);
		return (-1);
	}
	(*cmds)->infile = open(tokens->str, O_RDONLY, 0666);
	if ((*cmds)->infile == -1)
	{
		if (open_error(tokens->str, minishell) == -1)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int	output(t_cmds **cmds, t_tokens *tokens, t_minishell *minishell)
{
	if ((*cmds)->outfile != -1 && close((*cmds)->outfile) == -1)
	{
		write(2, "minishell: close: ", 17);
		ft_perror(tokens->str, minishell, 1);
		return (-1);
	}
	(*cmds)->outfile = open(tokens->str,
			O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if ((*cmds)->outfile == -1)
	{
		if (open_error(tokens->str, minishell) == -1)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int	append(t_cmds **cmds, t_tokens *tokens, t_minishell *minishell)
{
	if ((*cmds)->outfile != -1 && close((*cmds)->outfile) == -1)
	{
		write(2, "minishell: close: ", 17);
		ft_perror(tokens->str, minishell, 1);
		return (-1);
	}
	(*cmds)->outfile = open(tokens->str,
			O_CREAT | O_APPEND | O_WRONLY, 0666);
	if ((*cmds)->outfile == -1)
	{
		if (open_error(tokens->str, minishell) == -1)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int	heredoc_redir(t_cmds **cmds, t_tokens **tokens, t_minishell *minishell)
{
	if ((*cmds)->infile != -1 && close((*cmds)->infile) == -1)
	{
		write(2, "minishell: close: ", 17);
		perror((*tokens)->str);
		return (-1);
	}
	if (heredoc(cmds, tokens, minishell) == -1)
		return (-1);
	if ((*cmds)->infile == -1)
	{
		if (open_error("heredoc", minishell) == -1)
			return (-1);
		else
			return (1);
	}
	return (0);
}
