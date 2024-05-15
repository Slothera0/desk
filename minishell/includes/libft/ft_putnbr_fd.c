/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:33:36 by mbaron-t          #+#    #+#             */
/*   Updated: 2023/11/10 09:25:18 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	long long int	nb;
	size_t			len;

	len = 0;
	nb = (long long int) n;
	if (nb == 0)
		len++;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	tab[11];
	int		len;

	len = ft_len(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	tab[len] = 0;
	while (len > 0)
	{
		len--;
		tab[len] = n % 10 + 48;
		n /= 10;
	}
	ft_putstr_fd(tab, fd);
}
