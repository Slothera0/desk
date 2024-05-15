/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:19:19 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 19:19:13 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_var(size_t *k, size_t *j)
{
	(*j) = 0;
	(*k) = 0;
}

static int	parse_split(char **copy, char **split, size_t *i, size_t *k)
{
	size_t	temp;

	temp = 0;
	while (split[temp])
	{
		copy[*k] = ft_strdup(split[temp++]);
		if (!copy[(*k)++])
		{
			free_ptr_tab(copy);
			free_ptr_tab(split);
			return (-1);
		}
	}
	*i += (temp - 1);
	return (0);
}

static int	alloc_copy(char **copy, char **args, size_t *j, size_t *k)
{
	copy[*k] = ft_strdup(args[(*j)++]);
	if (!copy[(*k)++])
	{
		free_ptr_tab(copy);
		return (-1);
	}
	return (0);
}

char	**pro_expand(char **arg, size_t *i, t_minishell *minishell)
{
	char	**splt;
	char	**copy;
	size_t	ind[2];

	splt = ft_split(arg[*i], '\t');
	if (!splt)
		return (ft_perror(MALLOC_ERR, minishell, 1), NULL);
	copy = ft_calloc(ft_arraylen(splt) + ft_arraylen(arg) + 1,
			sizeof(char *));
	if (!copy && ft_perror(MALLOC_ERR, minishell, 1))
		return (free_ptr_tab(splt), NULL);
	init_var(&(ind[0]), &(ind[1]));
	while (arg[ind[1]])
	{
		if (!ft_strncmp(arg[ind[1]], splt[0], ft_strlen(splt[0])) && ++ind[1])
			if (parse_split(copy, splt, i, &(ind[0])) == -1)
				return (NULL);
		if (!arg[(ind[1])])
			break ;
		if (alloc_copy(copy, arg, &(ind[1]), &(ind[0])) == -1)
			return (free_ptr_tab(splt), NULL);
	}
	free_ptr_tab(splt);
	free_ptr_tab(arg);
	return (copy);
}
