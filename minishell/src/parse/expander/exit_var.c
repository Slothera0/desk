/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:38:42 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/25 13:58:35 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_exit_var(char *start, char *number, size_t len,
							t_minishell *minishell)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
	{
		ft_perror(MALLOC_ERR, minishell, 1);
		free(start);
		free(number);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (start[i])
		new[j++] = start[i++];
	i = 0;
	while (number[i])
		new[j++] = number[i++];
	free(start);
	free(number);
	return (new);
}

static char	*alloc_new(char *str, char *number, size_t *len,
						t_minishell *minishell)
{
	char	*new;

	(*len) = ft_strlen(str) + ft_strlen(number) - 2;
	new = ft_calloc((*len) + 1, sizeof(char));
	if (!new)
	{
		free(number);
		ft_perror(MALLOC_ERR, minishell, 1);
		return (NULL);
	}
	return (new);
}

static void	init_index(size_t *j, size_t *k)
{
	(*j) = 0;
	(*k) = 0;
}

static void	increase_index(char *number, size_t *j, size_t *k)
{
	(*j) += 2;
	(*k) += ft_strlen(number);
}

char	*exit_var(char *str, size_t *i, t_minishell *minishell)
{
	char	*number;
	char	*new;
	size_t	j;
	size_t	k;
	size_t	len;

	number = ft_itoa(minishell->exit_status);
	if (!number)
		return (ft_perror(MALLOC_ERR, minishell, 1), NULL);
	new = alloc_new(str, number, &len, minishell);
	init_index(&j, &k);
	while (new && str[j])
	{
		if (j == *i)
		{
			increase_index(number, &j, &k);
			new = join_exit_var(new, number, len, minishell);
			if (!new)
				return (ft_perror(MALLOC_ERR, minishell, 1), NULL);
		}
		if (!str[j])
			break ;
		new[k++] = str[j++];
	}
	return (free(str), new);
}
