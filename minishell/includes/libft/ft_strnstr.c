/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:01:52 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/08 15:31:27 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && i + j < len)
			{
				if (little[j + 1] == 0)
					return ((char *) &big[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
}
*/