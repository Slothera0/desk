/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:23:06 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 18:50:07 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

static int	set_var(char *var, char ***env);
static int	add_mem(char ***env);
static int	check_name(char *var);

int	export(char ***env, char **define)
{
	int	i;
	int	temp;

	i = 0;
	while (define[i])
	{
		temp = set_var(define[i], env);
		if (temp == 1)
			return (error("minishell: export"));
		else if (temp == 2)
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(define[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
		}
		i++;
	}
	return (0);
}

static int	set_var(char *var, char ***env)
{
	int	i;
	int	j;

	i = check_name(var);
	if (i == -1)
		return (2);
	if (!var[i])
		return (0);
	j = 0;
	while ((*env)[j])
	{
		if (ft_strncmp((*env)[j], var, i + 1) == 0)
			break ;
		j++;
	}
	if (!(*env)[j] && add_mem(env))
		return (1);
	if ((*env)[j])
		free((*env)[j]);
	(*env)[j] = ft_strdup(var);
	return (0);
}

static int	add_mem(char ***env)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_calloc(sizeof(char *), (ft_arraylen((*env)) + 2));
	if (!temp)
		return (1);
	while ((*env)[i])
	{
		temp[i] = (*env)[i];
		i++;
	}
	free (*env);
	*env = temp;
	return (0);
}

static int	check_name(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
	{
		if (i == 0 && ft_isdigit(var[i]))
			return (-1);
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	return (i);
}
