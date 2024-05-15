/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:12:06 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/13 15:12:01 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (*lst == NULL)
		return ;
	if ((*del) == NULL)
		return ;
	while ((*lst)->next != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), (*del));
		*lst = temp;
	}
	ft_lstdelone((*lst), (*del));
	*lst = NULL;
}
