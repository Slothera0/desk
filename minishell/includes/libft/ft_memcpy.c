/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:35:03 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/10 15:16:06 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tab_dest;
	char	*tab_src;
	size_t	i;

	i = -1;
	tab_dest = (char *) dest;
	tab_src = (char *) src;
	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	while (++i < n)
		tab_dest[i] = tab_src[i];
	return ((void *) tab_dest);
}
