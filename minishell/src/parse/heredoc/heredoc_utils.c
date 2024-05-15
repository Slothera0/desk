/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:41:27 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/23 15:41:31 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delimiter_quote(char *str, t_minishell *minishell)
{
	char	quote;
	size_t	start;
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == DQUOTE || str[i] == SQUOTE)
		{
			quote = str[i];
			start = i++;
			while (str[i] != quote)
				i++;
			str = quotes_remover(str, start, &i, minishell);
			if (!str)
				return (NULL);
		}
		else
			i++;
	}
	return (str);
}
