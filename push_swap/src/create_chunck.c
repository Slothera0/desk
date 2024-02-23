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

void	create_chunck(t_pile *pile_a, t_pile *pile_b)
{
	double	chunck;

	chunck = 0.065 * pile_a->len + 23.5;
	if (pile_a->len < 100)
		chunck -= 22;
	while (pile_a->len > 3)
		push_n_to_b(pile_a, pile_b, chunck);
}

void	push_n_to_b(t_pile *pile_a, t_pile *pile_b, int n)
{
	int	max_ten;
	int	median_ten;
	int	count;

	max_ten = search_max_n(pile_a, n);
	median_ten = search_max_n(pile_a, n / 2);
	count = 0;
	while (count < n && pile_a->len > 3)
	{
		if (pile_a->pile[0] <= max_ten
			&& pile_a->pile[0] < search_max_n(pile_a, pile_a->len - 3))
		{
			push_one_to_b(pile_a, pile_b, median_ten);
			count++;
		}
		else
		{
			rotate(pile_a->pile, pile_a->len);
			if (write(1, "ra\n", 3) == -1)
				error(pile_a, pile_b);
		}
	}
}

void	push_one_to_b(t_pile *pile_a, t_pile *pile_b, int median_ten)
{
	push(pile_b->pile, &(pile_b->len), pile_a->pile, &(pile_a->len));
	if (write(1, "pb\n", 3) == -1)
		error(pile_a, pile_b);
	if (pile_b->pile[0] < median_ten)
	{
		rotate(pile_b->pile, pile_b->len);
		if (write(1, "rb\n", 3) == -1)
			error(pile_a, pile_b);
	}
}

int	search_max_n(t_pile *pile, int n)
{
	int	i;
	int	j;
	int	max;
	int	temp;

	max = min(pile->pile, pile->len);
	i = 0;
	if (pile->pile[0] != max)
		temp = pile->pile[0];
	else
		temp = pile->pile[1];
	while (i < n && i < pile->len)
	{
		j = 0;
		while (j < pile->len)
		{
			if ((pile->pile[j] < temp || temp == max) && pile->pile[j] > max)
				temp = pile->pile[j];
			j++;
		}
		max = temp;
		i++;
	}
	return (max);
}
