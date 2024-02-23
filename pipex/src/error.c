/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:16:27 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/23 16:52:25 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	error(int error_id, int fd[3], char *path, char **cmd)
{
	int	i;

	i = 0;
	free_fd(fd);
	if (path)
		free(path);
	if (cmd)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
	}
	free(cmd);
	exit(error_id);
}

void	free_fd(int fd[3])
{
	if (fd)
	{
		if (fd[0] != -1)
		{
			close(fd[0]);
			fd[0] = -1;
		}
		if (fd[1] != -1)
		{
			close(fd[1]);
			fd[1] = -1;
		}
		if (fd[2] != -1)
		{
			close(fd[2]);
			fd[2] = -1;
		}
	}
}

void	print_error(int error_id)
{
	if (error_id == 0)
		ft_putstr_fd("Error : wrong number of arguments\n", 2);
	if (error_id == 1)
		ft_putstr_fd("Error : can't open the pipe\n", 2);
	if (error_id == 2)
		ft_putstr_fd("Error : can't use fork()\n", 2);
	if (error_id == 3)
		ft_putstr_fd("Error : can't close the pipe or the file\n", 2);
	if (error_id == 4)
		ft_putstr_fd("Error : problem with waitpid()\n", 2);
	if (error_id == 5)
		ft_putstr_fd("Error : problem when parsing the command\n", 2);
	if (error_id == 6)
		ft_putstr_fd("Error : can't open the file\n", 2);
	if (error_id == 7)
		ft_putstr_fd("Error : problem with dup2()\n", 2);
	if (error_id < 3)
		exit(EXIT_FAILURE);
}
