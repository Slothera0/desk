/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:35:46 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/19 13:37:46 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_envp(char **envp)
{
	char	**new_env;
	size_t	i;

	i = 0;
	while (envp[i])
		i++;
	new_env = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (new_env);
}
