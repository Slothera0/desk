/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:08:34 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 16:41:49 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(t_minishell *minishell)
{
	char	*line;

	line = NULL;
	line = readline("minishell$ ");
	if (line == NULL)
	{
		write(1, "exit\n", 5);
		free_ptr_tab(minishell->envp);
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
	if (ft_strlen(line) > 0)
	{
		add_history(line);
		if (parsing(line, minishell) != -1)
			exec(minishell);
	}
	free(line);
}

int	main(int argc, char *argv[], char **envp)
{
	t_minishell	minishell;

	(void)argc;
	(void)argv;
	if (envp)
		minishell.envp = init_envp(envp);
	else
		minishell.envp = ft_calloc(1, sizeof(char *));
	minishell.exit_status = 0;
	while (1)
	{
		minishell.index = -1;
		minishell.pipe = false;
		init_sig(&minishell);
		prompt(&minishell);
	}
}
