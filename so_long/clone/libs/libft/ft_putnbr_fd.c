/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:59:58 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:48:20 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	if (n < -9)
	{
		if (ft_putchar_fd('-', fd) < 0 || ft_putnbr_fd(-(n / 10), fd) < 0 \
			|| ft_putchar_fd(-(n % 10) + '0', fd) < 0)
			return (-1);
	}
	else if (n > 9)
	{
		if (ft_putnbr_fd(n / 10, fd) < 0 || ft_putchar_fd(n % 10 + '0', fd) < 0)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar_fd('-', fd) < 0 || ft_putchar_fd(-n + '0', fd) < 0)
				return (-1);
		}
		else if (ft_putchar_fd(n + '0', fd) < 0)
			return (-1);
	}
	return (1);
}
