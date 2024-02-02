/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:35:19 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/31 10:40:16 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_chunck(int *pile_a, int *len_a, int *pile_b, int *len_b)
{
	double	chunck;

	chunck = 0.065 * *len_a + 23.5;
	if (*len_a < 100)
		chunck -= 22;
	while (*len_a > 3)
		push_n(pile_a, len_a, pile_b, len_b, chunck);
}

void	push_n(int *pile_a, int *len_a, int *pile_b, int *len_b, int n)
{
	int	max_ten;
	int	median_ten;
	int	count;

	max_ten = search_max_n(pile_a, *len_a, n);
	median_ten = search_max_n(pile_a, *len_a, n / 2);
	count = 0;
	while (count < n && *len_a > 3)
	{
		if (pile_a[0] <= max_ten && pile_a[0] < search_max_n(pile_a, *len_a, *len_a - 3))
		{
			push(pile_b, len_b, pile_a, len_a);
			write(1, "pb\n", 3);
			count++;
			if (pile_b[0] < median_ten)
			{
				rotate(pile_b, *len_b);
				write(1, "rb\n", 3);
			}
		}
		else
		{
			rotate(pile_a, *len_a);
			write(1, "ra\n", 3);
		}
	}
}

int	search_max_n(int *pile, int len, int n)
{
	int	i;
	int	j;
	int	max;
	int	temp;

	max = min(pile, len);
	i = 0;
	if (pile[0] != max)
		temp = pile[0];
	else
		temp = pile[1];
	while (i < n && i < len)
	{
		j = 0;
		while (j < len)
		{
			if ((pile[j] < temp || temp == max) && pile[j] > max)
				temp = pile[j];
			j++;
		}
		max = temp;
		i++;
	}
	return (max);
}
