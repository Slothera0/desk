/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:22:50 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/26 15:40:48 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error(char *str)
{
	perror(str);
	return (1);
}

int	error_msg(char *cmd, char *msg)
{
	ft_putstr_fd("minishell: exec: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	if (cmd)
		free(cmd);
	return (1);
}
