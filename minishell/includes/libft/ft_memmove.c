/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:47:39 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/10 15:16:13 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tab_dest;
	char	*tab_src;
	size_t	i;

	tab_dest = dest;
	tab_src = (char *) src;
	i = -1;
	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	if (tab_dest > tab_src)
		while (n-- > 0)
			tab_dest[n] = tab_src[n];
	else
		while (++i < n)
			tab_dest[i] = tab_src[i];
	return (tab_dest);
}
