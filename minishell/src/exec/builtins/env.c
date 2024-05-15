/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:22:57 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/26 13:17:28 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(char **envp, int outfile)
{
	int	i;

	i = 0;
	if (outfile == -1)
		outfile = 1;
	if (!envp || !envp[0])
		return (0);
	while (envp[i])
	{
		ft_putendl_fd(envp[i], outfile);
		i++;
	}
	return (0);
}
