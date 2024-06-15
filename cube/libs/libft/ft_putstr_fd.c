/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:59:40 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:12:27 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		count;

	count = 0;
	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		count += ft_putchar_fd(s[i], fd);
		if (count < 0)
			return (-1);
		i++;
	}
	return (count);
}
