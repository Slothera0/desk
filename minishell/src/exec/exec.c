/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:48:21 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/26 18:01:37 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

static int	do_fork(t_cmds *cmd, char **envp, t_cmds *start);
static int	exec_cmd(t_cmds *cmd, char **envp);
static int	set_pipe(t_cmds *cmd);
static	int	close_child_fd(t_cmds *cmd);

int	exec(t_minishell *data)
{
	t_cmds	*c_cmd;
	int		pid;
	int		status;

	c_cmd = data->cmds;
	data->exit_status = 1;
	if (c_cmd->next == NULL && c_cmd->args && is_builtin(c_cmd->args[0]))
	{
		data->exit_status = exec_builtins(data, c_cmd, data->envp);
		return (free_data(data), 0);
	}
	while (c_cmd)
	{
		if (c_cmd->next && set_pipe(c_cmd))
			return (free_data(data), error("minishell: exec"));
		pid = do_fork(c_cmd, data->envp, data->cmds);
		if (pid == -1)
			return (free_data(data), error("minishell: exec"));
		c_cmd = c_cmd->next;
	}
	waitpid(pid, &status, 0);
	data->exit_status = WEXITSTATUS(status);
	while (waitpid(-1, NULL, 0) > 0)
		;
	return (free_data(data), 0);
}

static int	exec_cmd(t_cmds *cmd, char **envp)
{
	if (close_child_fd(cmd))
		return (1);
	if (is_builtin(cmd->args[0]))
		return (exec_builtins(NULL, cmd, envp));
	if (cmd->infile != -1 && dup2(cmd->infile, 0) == -1)
		return (error("minishell: exec"));
	if (cmd->infile != -1 && close(cmd->infile) == -1)
		return (error("minishell: exec"));
	if (cmd->outfile != -1 && dup2(cmd->outfile, 1) == -1)
		return (error("minishell: exec"));
	if (cmd->outfile != -1 && close(cmd->outfile) == -1)
		return (error("minishell: exec"));
	cmd->path = find_path(envp, cmd->args[0]);
	if (!cmd->path && errno != 20 && errno != 0)
	{
		ft_putstr_fd("minishell: exec: ", 2);
		return (error(cmd->args[0]));
	}
	if (cmd->path && access(cmd->path, X_OK) == -1)
		return (error_msg(cmd->path, "Permission denied"));
	execve(cmd->path, cmd->args, envp);
	if (errno == 13)
		return (error_msg(cmd->path, "Is a directory"), 126);
	error_msg(ft_strdup(cmd->args[0]), "command not found");
	return (127);
}

static int	set_pipe(t_cmds *cmd)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	if (cmd->outfile == -1)
		cmd->outfile = fd[1];
	else if (close(fd[1]) == -1)
		return (1);
	if (cmd->next->infile == -1)
		cmd->next->infile = fd[0];
	else if (close(fd[0]) == -1)
		return (1);
	return (0);
}

static int	do_fork(t_cmds *cmd, char **envp, t_cmds *start)
{
	int	pid;
	int	temp;

	if (cmd->args == NULL)
		return (1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (!cmd->args[0] || !cmd->args[0][0])
			temp = 0;
		else
			temp = exec_cmd(cmd, envp);
		ft_free_array(envp);
		free_cmd(start);
		exit(temp);
	}
	if (cmd->infile != -1 && close(cmd->infile) == -1)
		return (error("minishell: exec"));
	cmd->infile = -1;
	if (cmd->outfile != -1 && close(cmd->outfile) == -1)
		return (error("minishell: exec"));
	cmd->outfile = -1;
	return (pid);
}

static	int	close_child_fd(t_cmds *cmd)
{
	t_cmds	*temp;

	temp = cmd->next;
	cmd->next = NULL;
	cmd = temp;
	while (cmd)
	{
		if (cmd->infile != -1 && close(cmd->infile) == -1)
			return (error("minishell: exec"));
		if (cmd->outfile != -1 && close(cmd->outfile) == -1)
			return (error("minishell: exec"));
		if (cmd->args)
			ft_free_array(cmd->args);
		temp = cmd->next;
		free(cmd);
		cmd = temp;
	}
	return (0);
}
