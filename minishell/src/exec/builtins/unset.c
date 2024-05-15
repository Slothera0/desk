/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:23:14 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 15:48:13 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

int	del_var(char *var, char ***env);
int	del_mem(char ***env, int j);

int	unset(char ***env, char **var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (del_var(var[i], env))
			return (error("minishell: unset"));
		i++;
	}
	return (0);
}

int	del_var(char *var, char ***env)
{
	int		j;
	char	*temp;

	j = 0;
	while ((*env)[j])
	{
		temp = ft_strdup_stop((*env)[j], '=', 0);
		if (!temp)
			return (1);
		if (ft_strncmp(temp, var, ft_strlen(temp) + 1) == 0)
		{
			free(temp);
			break ;
		}
		free(temp);
		j++;
	}
	if (!(*env)[j])
		return (0);
	del_mem(env, j);
	return (0);
}

int	del_mem(char ***env, int j)
{
	int		i;
	char	**temp;
	int		boolean;

	i = 0;
	boolean = 0;
	temp = malloc(sizeof(char *) * (ft_arraylen((*env))));
	if (!temp)
		return (1);
	while ((*env)[i])
	{
		if (i != j)
			temp[i - boolean] = (*env)[i];
		else
		{
			boolean = 1;
			free((*env)[i]);
		}
		i++;
	}
	temp[i - boolean] = NULL;
	free (*env);
	*env = temp;
	return (0);
}
