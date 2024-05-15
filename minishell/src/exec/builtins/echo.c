/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:34:52 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/26 18:53:16 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_n_option(char *str);

int	echo(t_cmds *cmd)
{
	int	i;
	int	bool_n;

	bool_n = 0;
	i = 1;
	if (cmd->outfile == -1)
		cmd->outfile = 1;
	while (is_n_option(cmd->args[i]) == 1)
	{
		bool_n = 1;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], cmd->outfile);
		if (cmd->args[i][0] && cmd->args[i + 1])
			ft_putchar_fd(' ', cmd->outfile);
		i++;
	}
	if (bool_n == 0)
		ft_putchar_fd('\n', cmd->outfile);
	if (cmd->outfile == 1)
		cmd->outfile = -1;
	return (0);
}

int	is_n_option(char *str)
{
	int	i;

	i = 1;
	if (!str || str[0] != '-')
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i])
		return (0);
	return (1);
}
