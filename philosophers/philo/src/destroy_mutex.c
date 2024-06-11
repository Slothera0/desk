/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:41:34 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 15:54:25 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_lock *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&(tab[i].mutex));
		i++;
	}
}

void	destroy_mutex_p(t_philo *philo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&(philo[i].nb_eat.mutex));
		pthread_mutex_destroy(&(philo[i].last_eat.mutex));
		i++;
	}
}
