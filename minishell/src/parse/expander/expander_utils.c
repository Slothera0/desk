/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:48:09 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/19 14:53:36 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	filler(char **split, char *line, size_t i, t_minishell *minishell)
{
	size_t	temp;

	split[0] = ft_substr(line, 0, i++);
	if (!split[0])
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		free_ptr_tab(split);
		return (-1);
	}
	temp = i;
	while (line[i])
		i++;
	split[1] = ft_substr(line, temp, i);
	if (!split[1])
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		free_ptr_tab(split);
		return (-1);
	}
	return (0);
}

char	**envp_split(char *line, t_minishell *minishell)
{
	size_t	i;
	char	**split;

	split = ft_calloc(4, sizeof(char *));
	if (!split)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (filler(split, line, i, minishell) == -1)
		return (NULL);
	return (split);
}
