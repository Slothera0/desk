/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:35:11 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/23 16:54:40 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	exec_first_cmd(char *infile, char *cmd, int fd[3], char **envp)
{
	char	*cmd_path;
	char	**cmd_split;

	if (close(fd[0]) == -1)
		error(3, fd, NULL, NULL);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		error(5, fd, NULL, NULL);
	cmd_path = find_path(envp, cmd_split[0]);
	if (!cmd_path)
		error(5, fd, NULL, cmd_split);
	if (access(infile, R_OK) != 0)
		error(6, fd, cmd_path, cmd_split);
	fd[2] = open(infile, O_RDONLY);
	if (fd[2] == -1)
		error(6, fd, cmd_path, cmd_split);
	if (dup2(fd[2], 0) == -1)
		error(7, fd, cmd_path, cmd_split);
	if (dup2(fd[1], 1) == -1)
		error(7, fd, cmd_path, cmd_split);
	if (close(fd[1]) == -1)
		error(3, fd, cmd_path, cmd_split);
	execve(cmd_path, cmd_split, envp);
	perror("Error during execve");
	error(8, fd, cmd_path, cmd_split);
}

void	exec_second_cmd(char *outfile, char *cmd, int fd[3], char **envp)
{
	char	*cmd_path;
	char	**cmd_split;

	if (close(fd[1]) == -1)
		error(3, fd, NULL, NULL);
	fd[2] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[2] == -1)
		error(6, fd, NULL, NULL);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		error(5, fd, NULL, NULL);
	cmd_path = find_path(envp, cmd_split[0]);
	if (!cmd_path)
		error(5, fd, NULL, cmd_split);
	if (dup2(fd[2], 1) == -1)
		error(7, fd, cmd_path, cmd_split);
	if (dup2(fd[0], 0) == -1)
		error(7, fd, cmd_path, cmd_split);
	if (close(fd[0]) == -1)
		error(3, fd, cmd_path, cmd_split);
	execve(cmd_path, cmd_split, envp);
	perror("Error during execve");
	error(8, fd, cmd_path, cmd_split);
}
