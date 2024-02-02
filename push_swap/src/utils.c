/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:19:45 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/31 07:57:37 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_pile(char	**str, int len)
{
	int		i;
	int		*pile;
	long	temp;

	i = 0;
	pile = malloc(sizeof(int) * (len));
	if (!pile)
		return (NULL);
	if (str == NULL)
		return (pile);
	while (i < len)
	{
		temp = ft_atol(str[i]);
		if (temp > INT_MAX)
			return (NULL);
		pile[i] = temp;
		i++;
	}
	return (pile);
}

long	ft_atol(char *str)
{
	int		sign;
	int		i;
	long	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - '0';
		if (nbr > INT_MAX)
			return (LONG_MAX);
		i++;
	}
	if (str[i])
		return (LONG_MAX);
	nbr *= sign;
	return (nbr);
}

int	is_sorted(int *pile, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (pile[i] < pile[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int error()
{
	write(2, "Error\n", 6);
	return (1);
}

int	is_double(int *pile, int len)
{
	int	i;
	int	j;

	i = 0;
	if (!pile)
		return (1);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (pile[i] == pile[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
