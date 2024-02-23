/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:02:50 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/23 16:51:50 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define CONST_PATH "PATH=/home/arvoyer/bin:/usr/local/sbin:/usr/local/bin\
:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

void	error(int error_id, int fd[3], char *path, char **cmd);
char	*find_path(char **envp, char *cmd);
char	*search_access(char *str, char *cmd);
void	exec_first_cmd(char *infile, char *cmd, int fd[3], char **envp);
void	exec_second_cmd(char *outfile, char *cmd, int fd[3], char **envp);
void	print_error(int error_id);
void	free_fd(int fd[3]);
void	init_fork(char **argv, char **envp, int fd[3], int pid[2]);

#endif