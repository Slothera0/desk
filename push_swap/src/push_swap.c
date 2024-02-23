/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:17:38 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/09 06:18:37 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**str;
	int		len;

	if (argc == 1)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		if (!check_arg(argv[1]))
			error(NULL, NULL);
		str = ft_split(argv[1]);
		if (!str)
			error(NULL, NULL);
		len = ft_strlen_p(str);
		if (!push_swap(str, len))
		{
			free_array(str, len);
			error(NULL, NULL);
		}
		free_array(str, len);
	}
	else if (!push_swap(&(argv[1]), argc - 1))
		error(NULL, NULL);
	return (EXIT_SUCCESS);
}

int	push_swap(char **argv, int len_a)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = init_pile(argv, len_a);
	pile_b = init_pile(NULL, len_a);
	if (!pile_a || !pile_b)
		return (free_struct(pile_a), free_struct(pile_b), 0);
	pile_a->len = len_a;
	if (is_double(pile_a->pile, pile_a->len))
		return (free_struct(pile_a), free_struct(pile_b), 0);
	pile_b->len = 0;
	if (!is_sorted(pile_a->pile, pile_a->len))
	{
		create_chunck(pile_a, pile_b);
		sort_tab(pile_a, pile_b);
	}
	return (free_struct(pile_a), free_struct(pile_b), 1);
}
