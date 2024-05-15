/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:50:40 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/24 14:50:40 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(char *str, size_t *i, size_t len, t_minishell *minishell)
{
	char	*temp;

	temp = ft_substr(str, *i, len);
	if (!temp)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		free(str);
		return (NULL);
	}
	return (temp);
}

size_t	get_len(char *str, size_t *i, size_t *j)
{
	size_t	len;

	(*j) = 0;
	len = 0;
	(*i)++;
	while (str[*i + len] && (ft_isalnum(str[*i + len]) || str[*i + len] == '_'))
		len++;
	return (len);
}

bool	check_var(char *temp, char **infos)
{
	if (!ft_strncmp(temp, infos[0], ft_strlen(infos[0]))
		&& !ft_strncmp(temp, infos[0], ft_strlen(temp)))
	{
		free(temp);
		return (true);
	}
	return (false);
}

char	**get_infos(char *str, char *line, t_minishell *minishell)
{
	char	**infos;

	infos = envp_split(line, minishell);
	if (!infos)
	{
		free(str);
		return (NULL);
	}
	return (infos);
}
