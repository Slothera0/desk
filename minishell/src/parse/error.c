/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:13:03 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/22 14:13:03 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_error(char *msg, t_minishell *minishell, int status)
{
	write(2, msg, ft_strlen(msg));
	minishell->exit_status = status;
	return (1);
}

int	ft_perror(char *prefix, t_minishell *minishell, int status)
{
	perror(prefix);
	minishell->exit_status = status;
	return (1);
}
