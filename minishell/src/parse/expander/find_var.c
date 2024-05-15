/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:00:42 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 14:41:38 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*not_found(char *str, size_t *i, size_t len, bool in_quotes)
{
	char	*temp;

	(*i)--;
	temp = var_remover(str, *i, len);
	if (!temp)
		return (NULL);
	if (in_quotes)
		(*i)--;
	return (temp);
}

static void	end_loop(char *temp, char **infos, size_t *j,
						t_minishell *minishell)
{
	free_ptr_tab(infos);
	(*j)++;
	if (!minishell->envp[*j])
		free(temp);
}

static void	if_quotes(bool in_quotes, size_t *i)
{
	if (in_quotes)
		(*i)--;
}

char	*find_var(char *str, size_t *i,
					t_minishell *minishell, bool in_quotes)
{
	char	*temp;
	char	**infos;
	size_t	len;
	size_t	j;

	len = get_len(str, i, &j);
	temp = get_var(str, i, len, minishell);
	if (!temp)
		return (NULL);
	while (minishell->envp[j])
	{
		infos = get_infos(str, minishell->envp[j], minishell);
		if (!infos)
			return (free(temp), NULL);
		if (check_var(temp, infos))
		{
			temp = replace_var(str, i, len, infos);
			if_quotes(in_quotes, i);
			break ;
		}
		end_loop(temp, infos, &j, minishell);
	}
	if (!minishell->envp[j])
		temp = not_found(str, i, len, in_quotes);
	return (temp);
}
