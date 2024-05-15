/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:55:27 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/13 15:32:45 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*element;
	void	*temp;

	new = NULL;
	while (lst != NULL && (*f) && (*del))
	{
		temp = (*f)(lst->content);
		if (!temp)
		{
			ft_lstclear(&new, (*del));
			return (NULL);
		}
		element = ft_lstnew(temp);
		if (!element)
		{
			(*del)(temp);
			ft_lstclear(&new, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
