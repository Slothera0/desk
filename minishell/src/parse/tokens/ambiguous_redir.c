/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:30:40 by mbaron-t          #+#    #+#             */
/*   Updated: 2024/04/26 18:32:52 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_ambi_error(t_tokens **tokens, char *non_expand,
							t_minishell *minishell)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(non_expand, 2);
	ft_putendl_fd(": ambiguous redirect", 2);
	minishell->exit_status = 1;
	(*tokens)->token = AMBIGUOUS;
}

void	ambiguous_redirect(t_tokens **tokens, char *non_expand,
							t_minishell *minishell)
{
	size_t	i;
	bool	quote;

	i = 0;
	quote = false;
	if (!(*tokens)->str[0])
		print_ambi_error(tokens, non_expand, minishell);
	if (non_expand[0] == DQUOTE || non_expand[0] == SQUOTE)
		quote = true;
	while (!quote && (*tokens)->str[i])
	{
		if (is_space((*tokens)->str[i]))
			print_ambi_error(tokens, non_expand, minishell);
		i++;
	}
	free(non_expand);
}
