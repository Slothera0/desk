/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:56:16 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/09 06:19:46 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_array(char **tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	error(t_pile *pile_a, t_pile *pile_b)
{
	free_struct(pile_a);
	free_struct(pile_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_struct(t_pile *pile)
{
	if (!pile)
		return ;
	free(pile->pile);
	free(pile);
}
