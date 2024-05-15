/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:19:19 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 14:44:00 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtins(t_minishell *data, t_cmds *cmd, char **envp)
{
	if (!(cmd->args))
		return (1);
	if (!ft_strncmp(cmd->args[0], "cd\0", 3) && data)
		return (cd(&envp, cmd->args[1]));
	else if (!ft_strncmp(cmd->args[0], "cd\0", 3))
		return (cd(NULL, cmd->args[1]));
	if (!ft_strncmp(cmd->args[0], "echo\0", 5))
		return (echo(cmd));
	if (!ft_strncmp(cmd->args[0], "env\0", 4))
		return (env(envp, cmd->outfile));
	if (!ft_strncmp(cmd->args[0], "exit\0", 5))
		return (exit_cmd(cmd->args, data));
	if (!ft_strncmp(cmd->args[0], "export\0", 7) && data)
		return (export(&(data->envp), &(cmd->args[1])));
	else if (!ft_strncmp(cmd->args[0], "export\0", 7))
		return (export(NULL, &(cmd->args[1])));
	if (!ft_strncmp(cmd->args[0], "pwd\0", 4))
		return (pwd(cmd->outfile));
	if (!ft_strncmp(cmd->args[0], "unset\0", 6) && data)
		return (unset(&(data->envp), &(cmd->args[1])));
	else if (!ft_strncmp(cmd->args[0], "unset\0", 6))
		return (unset(NULL, &(cmd->args[1])));
	return (0);
}

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "cd\0", 3))
		return (1);
	if (!ft_strncmp(cmd, "echo\0", 5))
		return (1);
	if (!ft_strncmp(cmd, "env\0", 4))
		return (1);
	if (!ft_strncmp(cmd, "exit\0", 5))
		return (1);
	if (!ft_strncmp(cmd, "export\0", 7))
		return (1);
	if (!ft_strncmp(cmd, "pwd\0", 4))
		return (1);
	if (!ft_strncmp(cmd, "unset\0", 6))
		return (1);
	return (0);
}
