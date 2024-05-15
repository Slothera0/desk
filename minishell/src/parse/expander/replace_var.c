/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:27:18 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/25 13:45:54 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_var(char **temp, char **infos, char *str)
{
	char	*join;
	char	*new;

	free(str);
	join = ft_strjoin(temp[0], infos[1]);
	if (!join)
	{
		free_ptr_tab(infos);
		free_ptr_tab(temp);
		return (NULL);
	}
	new = ft_strjoin(join, temp[1]);
	if (!new)
	{
		free_ptr_tab(infos);
		free(join);
		free_ptr_tab(temp);
		return (NULL);
	}
	free(join);
	free_ptr_tab(temp);
	return (new);
}

static char	**store_str(char *str, size_t *i, size_t var_len)
{
	size_t	j;
	char	**temp;

	temp = ft_calloc(3, sizeof(char *));
	if (!temp)
		return (NULL);
	temp[0] = ft_substr(str, 0, *i - 1);
	if (!temp[0])
	{
		free_ptr_tab(temp);
		return (NULL);
	}
	j = 0;
	while (str[*i - 1 + var_len + j])
		j++;
	temp[1] = ft_substr(str, *i + var_len, j);
	if (!temp[1])
	{
		free_ptr_tab(temp);
		return (NULL);
	}
	return (temp);
}

static void	replace_space_tab(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '\t';
		i++;
	}
}

char	*replace_var(char *str, size_t *i, size_t var_len, char **infos)
{
	char	*new;
	char	**temp;

	temp = store_str(str, i, var_len);
	if (!temp)
	{
		free_ptr_tab(infos);
		free(str);
		return (NULL);
	}
	new = join_var(temp, infos, str);
	if (!new)
		return (NULL);
	*i = *i + ft_strlen(infos[1]) - 1;
	free_ptr_tab(infos);
	replace_space_tab(new);
	return (new);
}
