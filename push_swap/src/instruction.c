/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:51:47 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/03 16:46:59 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *pile_a, int *len_a, int *pile_b, int *len_b)
{
	int	temp;
	int	i;

	if ((*len_b) <= 0)
		return ;
	i = 1;
	temp = pile_b[0];
	while (i < (*len_b))
	{
		pile_b[i - 1] = pile_b[i];
		i++;
	}
	(*len_b)--;
	i = (*len_a);
	while (i > 0)
	{
		pile_a[i] = pile_a[i - 1];
		i--;
	}
	pile_a[0] = temp;
	(*len_a)++;
}

void	reverse_rotate(int *pile, int len)
{
	int	temp;
	int	i;

	i = len - 1;
	if (len <= 1)
		return ;
	temp = pile[len - 1];
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = temp;
}

void	rotate(int *pile, int len)
{
	int	temp;
	int	i;

	i = 1;
	if (len <= 1)
		return ;
	temp = pile[0];
	while (i < len)
	{
		pile[i - 1] = pile[i];
		i++;
	}
	pile[len - 1] = temp;
}

void	swap(int *pile, int len)
{
	int	temp;

	if (len <= 1)
		return ;
	temp = pile[0];
	pile[0] = pile[1];
	pile[1] = temp;
}
