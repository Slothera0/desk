/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:02:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/23 16:53:25 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid[2];
	int	fd[3];
	int	wstatus;

	fd[2] = -1;
	if (argc != 5)
		print_error(0);
	if (pipe(fd) == -1)
		print_error(1);
	init_fork(argv, envp, fd, pid);
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		print_error(3);
	if (waitpid(pid[0], &wstatus, 0) == -1)
		print_error(4);
	if (WEXITSTATUS(wstatus) > 0)
		print_error(WEXITSTATUS(wstatus));
	if (waitpid(pid[1], &wstatus, 0) == -1)
		print_error(4);
	if (WEXITSTATUS(wstatus) > 0)
		print_error(WEXITSTATUS(wstatus));
	return (EXIT_SUCCESS);
}

void	init_fork(char **argv, char **envp, int fd[3], int pid[2])
{
	pid[0] = fork();
	if (pid[0] == -1)
	{
		free_fd(fd);
		print_error(2);
	}
	if (pid[0] == 0)
		exec_first_cmd(argv[1], argv[2], fd, envp);
	pid[1] = fork();
	if (pid[1] == -1)
	{
		free_fd(fd);
		print_error(2);
	}
	if (pid[1] == 0)
		exec_second_cmd(argv[4], argv[3], fd, envp);
}
