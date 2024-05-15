/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:56 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/25 16:07:40 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_error(char *heredoc, int status)
{
	if (heredoc)
		free(heredoc);
	return (status);
}

static int	write_in_file(char *line, int fd, t_minishell *minishell)
{
	line = expander(line, minishell, true);
	if (!line)
		return (-1);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (0);
}

static int	read_loop(t_cmds *cmds, t_tokens **tokens, t_minishell *minishell)
{
	char	*line;

	(*tokens)->str = pre_expand((*tokens)->str, minishell);
	if (!(*tokens)->str)
		return (-1);
	(*tokens)->str = delimiter_quote((*tokens)->str, minishell);
	if (!(*tokens)->str)
		return (-1);
	while (true)
	{
		line = readline("> ");
		if (line == NULL)
		{
			printf("minishell: warning: here-document delimited"
				" by end-of-file (wanted `%s')\n", (*tokens)->str);
			return (0);
		}
		if (!ft_strncmp(line, (*tokens)->str, strlen(line))
			&& !ft_strncmp(line, (*tokens)->str, strlen((*tokens)->str)))
			break ;
		if (write_in_file(line, cmds->infile, minishell) == -1)
			return (-1);
	}
	free(line);
	return (0);
}

static int	unlink_temp(t_cmds **cmds, char *heredoc)
{
	if (close((*cmds)->infile) == -1)
		return (heredoc_error(heredoc, -1));
	(*cmds)->infile = open(heredoc, O_RDONLY, 0666);
	if ((*cmds)->infile == -1)
		return (1);
	if (unlink(heredoc) == -1)
		return (heredoc_error(heredoc, -1));
	free(heredoc);
	return (0);
}

int	heredoc(t_cmds **cmds, t_tokens **tokens, t_minishell *minishell)
{
	char	*heredoc;

	(*cmds)->infile = open("/dev/urandom", O_RDONLY, 0666);
	if ((*cmds)->infile == -1)
		return (1);
	heredoc = ft_calloc(6, sizeof(char));
	if (!heredoc)
		if (ft_perror(MALLOC_ERR, minishell, 1))
			return (-1);
	if (read((*cmds)->infile, heredoc, 5) == -1)
		return (heredoc_error(heredoc, 1));
	if (close((*cmds)->infile) == -1)
		return (heredoc_error(heredoc, -1));
	(*cmds)->infile = open(heredoc, O_CREAT | O_WRONLY, 0666);
	if ((*cmds)->infile == -1)
		return (heredoc_error(heredoc, 0));
	if (read_loop((*cmds), tokens, minishell) == -1)
		return (heredoc_error(heredoc, -1));
	return (unlink_temp(cmds, heredoc));
}
