/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:19:45 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/09 10:03:06 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*init_pile(char	**str, int len)
{
	int		i;
	t_pile	*pile;
	long	temp;

	i = 0;
	pile = malloc(sizeof(t_pile));
	if (!pile)
		return (NULL);
	pile->pile = malloc(sizeof(int) * (len));
	if (!(pile->pile))
		return (NULL);
	if (str == NULL)
		return (pile);
	while (i < len)
	{
		temp = ft_atol(str[i]);
		if (temp > INT_MAX)
			return (free(pile->pile), free(pile), NULL);
		pile->pile[i] = temp;
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
		if (nbr > INT_MAX && !(sign == -1 && nbr - 1 <= INT_MAX))
			return (LONG_MAX);
		i++;
	}
	if ((str[i] || i == 0) || (str[i - 1] < '0' || str[i - 1] > '9'))
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
