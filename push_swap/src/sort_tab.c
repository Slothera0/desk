/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 03:00:04 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/31 08:06:34 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *pile_a, int *len_a, int *pile_b, int *len_b)
{
	sort_three(pile_a, *len_a);
	if (pile_a[0] > pile_a[1])
	{
		swap(pile_a, *len_a);
		write(1, "sa\n", 3);
	}
	while (*len_b >= 1)
		push_n_sort(pile_a, len_a, pile_b, len_b);
	while (min(pile_a, *len_a) != pile_a[0])
	{
		reverse_rotate(pile_a, *len_a);
		write(1, "rra\n", 4);
	}
}

void	push_n_sort(int *pile_a, int *len_a, int *pile_b, int *len_b)
{
	if (pile_a[*len_a - 1] > max(pile_b, *len_b) && pile_a[*len_a - 1] != max(pile_a, *len_a))
	{
		reverse_rotate(pile_a, *len_a);
		write(1, "rra\n", 4);
	}
	else if (pile_b[0] == max(pile_b, *len_b))
	{
		push(pile_a, len_a, pile_b, len_b);
		write(1, "pa\n", 3);
	}
	else if (pile_b[0] > pile_a[*len_a - 1] || pile_a[*len_a - 1] == max(pile_a, *len_a))
	{
		push(pile_a, len_a, pile_b, len_b);
		write(1, "pa\n", 3);
		rotate(pile_a, *len_a);
		write(1, "ra\n", 3);
	}
	else if (dist_max(pile_b, *len_b) < *len_b / 2)
	{
		rotate(pile_b, *len_b);
		write(1, "rb\n", 3);
	}
	else
	{
		reverse_rotate(pile_b, *len_b);
		write(1, "rrb\n", 4);
	}
}

int	dist_max(int *pile, int len)
{
	int	i;

	i = 0;
	while (pile[i] != max(pile, len))
		i++;
	return (i);
}

void	sort_three(int *pile, int len)
{
	if (max(pile, len) == pile[0])
	{
		rotate(pile, len);
		write(1, "ra\n", 3);
	}
	else if (max(pile, len) == pile[1])
	{
		reverse_rotate(pile, len);
		write(1, "rra\n", 4);
	}
	if (pile[0] > pile[1])
	{
		swap(pile, len);
		write(1, "sa\n", 3);
	}
}