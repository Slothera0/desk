/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:17:38 by arvoyer           #+#    #+#             */
/*   Updated: 2024/01/31 07:50:12 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**str;
	int		len;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1]);
		if (!str)
			return (error());
		len = ft_strlen_p(str);
		if (!push_swap(str, len))
			return (free_array(str, len), error());
		free_array(str, len);
	}
	else if (!push_swap(&(argv[1]), argc - 1))
		return (error());
	return (0);
}

int	push_swap(char **argv, int len_a)
{
	int	*pile_a;
	int	*pile_b;
	int	len_b;

	pile_a = init_pile(argv, len_a);
	pile_b = init_pile(NULL, len_a);
	if (!pile_a || !pile_b || is_double(pile_a, len_a))
		return (free(pile_a), free(pile_b), 0);
	len_b = 0;
	if (!is_sorted(pile_a, len_a))
	{
		create_chunck(pile_a, &len_a, pile_b, &len_b);
		sort_tab(pile_a, &len_a, pile_b, &len_b);
	}
	return (free(pile_a), free(pile_b), 1);
}
