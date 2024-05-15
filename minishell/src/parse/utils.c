/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:14:59 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/03 11:10:30 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_token(char c)
{
	if (c == LESSER
		|| c == GREATER)
		return (true);
	return (false);
}

bool	is_space(char c)
{
	if (c == 32 || (c >= 9 & c <= 13))
		return (true);
	return (false);
}

int	quote_handler(const char *str, size_t *i)
{
	char	quote;

	quote = str[*i];
	if (quote != SQUOTE && quote != DQUOTE)
		return (0);
	while (str[++*i])
		if (str[*i] == quote)
			break ;
	if (!str[*i])
		return (-1);
	return (1);
}
