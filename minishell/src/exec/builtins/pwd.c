/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:23:10 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 18:33:07 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "minishell.h"

int	pwd(int outfile)
{
	char	*buf;

	if (outfile == -1)
		outfile = 1;
	buf = getcwd(NULL, 0);
	if (!buf)
		return (error("minishell: pwd"));
	ft_putendl_fd(buf, outfile);
	free(buf);
	return (0);
}
