/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:08:30 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/09 06:17:39 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int *pile, int len)
{
	int	min;
	int	i;

	i = 1;
	min = pile[0];
	while (i < len)
	{
		if (pile[i] < min)
			min = pile[i];
		i++;
	}
	return (min);
}

int	max(int *pile, int len)
{
	int	max;
	int	i;

	i = 1;
	max = pile[0];
	while (i < len)
	{
		if (pile[i] > max)
			max = pile[i];
		i++;
	}
	return (max);
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

int	dist_max(int *pile, int len)
{
	int	i;

	i = 0;
	while (pile[i] != max(pile, len))
		i++;
	return (i);
}
