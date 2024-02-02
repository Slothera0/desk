/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:08:30 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/31 05:23:26 by arvoyer          ###   ########.fr       */
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
