/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:17:16 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 15:39:43 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *s);

int	*error_arg(char *str)
{
	write(2, str, ft_strlen(str));
	return (NULL);
}

int	ft_atoi(const char *nptr)
{
	long int	nbr;
	int			i;

	nbr = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + nptr[i] - '0';
		if (nbr < 0)
			return (-2);
		i++;
	}
	if (nptr[i])
		return (-2);
	return (nbr);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
