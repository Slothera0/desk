/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoted_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:34:02 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 16:38:53 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	token_before_pipe(char *str, size_t pipe_i, t_minishell *minishell)
{
	size_t	i;
	bool	token;

	i = pipe_i;
	token = false;
	while (--i)
	{
		if (!is_space(str[i]))
		{
			if (is_token(str[i]))
			{
				token = true;
				break ;
			}
			else
			{
				token = false;
				break ;
			}
		}
	}
	if (token)
		parse_error("minishell: syntax error near unexpected token `|'\n",
			minishell, 2);
	return (token);
}

static int	only_space_pipe(char *str, size_t *i, t_minishell *minishell)
{
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == PIPE)
		if (parse_error("minishell: syntax error near unexpected token `|'\n",
				minishell, 2))
			return (-1);
	return (0);
}

static int	if_pipe(char *str, int *args, size_t *i, t_minishell *minishell)
{
	(*args)++;
	(*i)++;
	if (token_before_pipe(str, *i, minishell))
		return (-1);
	if (only_space_pipe(str, i, minishell) == -1)
		return (-1);
	return (0);
}

static int	count_pipe(char *str, t_minishell *minishell)
{
	size_t	i;
	int		args;

	i = 0;
	args = 0;
	if (only_space_pipe(str, &i, minishell) == -1)
		return (-1);
	while (str[i])
	{
		if (quote_handler(str, &i) == -1)
			if (parse_error("minishell: syntax error quote not closed\n",
					minishell, 2))
				return (-1);
		if (str[i] == PIPE)
		{
			if (if_pipe(str, &args, &i, minishell) == -1)
				return (-1);
		}
		else
			i++;
	}
	return (args);
}

char	**pipes_split(char *line, t_minishell *minishell)
{
	size_t	i;
	size_t	delim;
	int		args;
	char	**split;

	i = 0;
	args = count_pipe(line, minishell);
	split = init_split(line, args, &i, minishell);
	if (!split)
		return (NULL);
	if (args == 0)
		return (split);
	init_variables(&args, &delim, &i, minishell);
	while (line[++i])
	{
		quote_handler(line, &i);
		if (line[i] == PIPE)
		{
			split[args] = split_arg(line, &delim, i, minishell);
			if (!split[args++])
				return (NULL);
		}
	}
	split[args] = no_pipe_cmd(line, &i, delim, minishell);
	return (split);
}
