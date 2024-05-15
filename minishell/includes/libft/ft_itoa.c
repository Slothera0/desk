/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:23:48 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/10 09:25:03 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	long long int	nb;
	size_t			len;

	len = 0;
	nb = (long long int) n;
	if (nb <= 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char	*ft_fill_tab(char *tab, long long int n, size_t i, size_t len)
{
	if (n < 0)
	{
		n = -n;
		tab[0] = '-';
		i++;
	}
	tab[len] = 0;
	while (len > i)
	{
		len--;
		tab[len] = n % 10 + 48;
		n /= 10;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char			*result;
	long long int	nb;
	size_t			i;
	size_t			len;

	len = ft_len(n);
	i = 0;
	result = ft_calloc(sizeof(char), len + 1);
	nb = (long long int) n;
	if (!result)
		return (NULL);
	ft_fill_tab(result, nb, i, len);
	return (result);
}
