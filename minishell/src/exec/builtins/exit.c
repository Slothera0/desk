/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:23:01 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 15:47:23 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static int	too_many_arguments(void);

int	exit_cmd(char **status, t_minishell *data)
{
	long long	temp;

	ft_putendl_fd("exit", 2);
	if (status[1] == NULL)
		temp = data->exit_status;
	else
		temp = ft_atoll(status[1]);
	if (errno == 42)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(status[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		temp = 2;
	}
	if (status[1] && status[2] && errno != 42)
		return (too_many_arguments());
	if (data)
	{
		free_data(data);
		if (data->envp)
			ft_free_array(data->envp);
	}
	rl_clear_history();
	exit (temp);
}

static int	too_many_arguments(void)
{
	ft_putendl_fd("minishell: exit: too many arguments", 2);
	return (1);
}
