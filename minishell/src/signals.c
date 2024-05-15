/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:42:37 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/25 17:02:12 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_status(t_minishell *minishell)
{
	if (g_sig)
	{
		g_sig = false;
		minishell->exit_status = 130;
	}
}

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signum == SIGINT)
	{
		g_sig = true;
		write(1, "\n", 1);
		if (siginfo->si_pid != 0)
		{
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
		}
		return ;
	}
}

void	init_sig(t_minishell *minishell)
{
	struct sigaction	s_sigaction;

	sig_status(minishell);
	s_sigaction.sa_sigaction = sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGINT, &s_sigaction, NULL);
	signal(SIGQUIT, SIG_IGN);
}
