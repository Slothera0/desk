/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:27:49 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 14:46:47 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*potential_var(char *str, size_t *i,
						t_minishell *minishell, bool in_quotes)
{
	char	*new;

	if (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
		new = find_var(str, i, minishell, in_quotes);
	else if (str[*i + 1] == '?')
	{
		sig_status(minishell);
		new = exit_var(str, i, minishell);
		if (in_quotes)
			(*i)--;
	}
	else
	{
		new = str;
		if (!in_quotes)
			(*i)++;
	}
	if (!new)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	return (new);
}

static char	*squote_handler(char *str, size_t *i, t_minishell *minishell)
{
	size_t	j;

	j = *i;
	(*i)++;
	while (str[*i] != SQUOTE)
		(*i)++;
	str = quotes_remover(str, j, i, minishell);
	if (!str)
		return (NULL);
	return (str);
}

static char	*dquote_handler(char *str, size_t *i, t_minishell *minishell)
{
	size_t	j;

	j = *i;
	(*i)++;
	while (str[*i] != DQUOTE)
	{
		if (str[*i] == '$')
			str = potential_var(str, i, minishell, true);
		if (!str[*i])
			break ;
		(*i)++;
	}
	str = quotes_remover(str, j, i, minishell);
	if (!str)
		return (NULL);
	return (str);
}

char	*expander(char *str, t_minishell *minishell, bool heredoc)
{
	size_t	i;
	char	*new;

	i = 0;
	new = ft_strdup(str);
	if (!new)
		if (ft_perror(MALLOC_ERR, minishell, 1))
			return (NULL);
	if (!heredoc)
		new = pre_expand(new, minishell);
	while (new[i])
	{
		if (!heredoc && new[i] == SQUOTE)
			new = squote_handler(new, &i, minishell);
		else if (!heredoc && new[i] == DQUOTE)
			new = dquote_handler(new, &i, minishell);
		else if (new[i] == '$')
			new = potential_var(new, &i, minishell, false);
		else
			i++;
		if (!new)
			return (NULL);
	}
	return (new);
}
