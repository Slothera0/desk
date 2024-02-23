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

void	sort_tab(t_pile *pile_a, t_pile *pile_b)
{
	sort_three(pile_a, pile_b);
	if (pile_a->pile[0] > pile_a->pile[1])
	{
		swap(pile_a->pile, pile_a->len);
		if (write(1, "sa\n", 3) == -1)
			error(pile_a, pile_b);
	}
	while (pile_b->len >= 1)
	{
		if (pile_a->pile[pile_a->len - 1] > max(pile_b->pile, pile_b->len)
			&& pile_a->pile[pile_a->len - 1] != max(pile_a->pile, pile_a->len))
		{
			reverse_rotate(pile_a->pile, pile_a->len);
			if (write(1, "rra\n", 4) == -1)
				error(pile_a, pile_b);
		}
		else
			push_n_sort(pile_a, pile_b);
	}
	while (min(pile_a->pile, pile_a->len) != pile_a->pile[0])
	{
		reverse_rotate(pile_a->pile, pile_a->len);
		if (write(1, "rra\n", 4) == -1)
			error(pile_a, pile_b);
	}
}

void	push_n_sort(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->pile[0] == max(pile_b->pile, pile_b->len))
	{
		push(pile_a->pile, &(pile_a->len), pile_b->pile, &(pile_b->len));
		if (write(1, "pa\n", 3) == -1)
			error(pile_a, pile_b);
	}
	else if (pile_b->pile[0] > pile_a->pile[pile_a->len - 1]
		|| pile_a->pile[pile_a->len - 1] == max(pile_a->pile, pile_a->len))
	{
		push(pile_a->pile, &(pile_a->len), pile_b->pile, &(pile_b->len));
		rotate(pile_a->pile, pile_a->len);
		if (write(1, "pa\nra\n", 6) == -1)
			error(pile_a, pile_b);
	}
	else
		rotate_up_or_down(pile_a, pile_b);
}

void	rotate_up_or_down(t_pile *pile_a, t_pile *pile_b)
{
	if (dist_max(pile_b->pile, pile_b->len) < pile_b->len / 2)
	{
		rotate(pile_b->pile, pile_b->len);
		if (write(1, "rb\n", 3) == -1)
			error(pile_a, pile_b);
	}
	else
	{
		reverse_rotate(pile_b->pile, pile_b->len);
		if (write(1, "rrb\n", 4) == -1)
			error(pile_a, pile_b);
	}
}

void	sort_three(t_pile *pile_a, t_pile *pile_b)
{
	if (max(pile_a->pile, pile_a->len) == pile_a->pile[0])
	{
		rotate(pile_a->pile, pile_a->len);
		if (write(1, "ra\n", 3) == -1)
			error(pile_a, pile_b);
	}
	else if (max(pile_a->pile, pile_a->len) == pile_a->pile[1])
	{
		reverse_rotate(pile_a->pile, pile_a->len);
		if (write(1, "rra\n", 4) == -1)
			error(pile_a, pile_b);
	}
	if (pile_a->pile[0] > pile_a->pile[1])
	{
		swap(pile_a->pile, pile_a->len);
		if (write(1, "sa\n", 3) == -1)
			error(pile_a, pile_b);
	}
}
