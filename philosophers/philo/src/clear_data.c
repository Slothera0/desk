/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:17:58 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 15:57:32 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	destroy_mutex(t_lock *tab, int size);

void	clear_data(t_data data)
{
	size_t	i;

	destroy_mutex(data.philo[0].l_fork, data.size);
	free(data.philo[0].l_fork);
	destroy_mutex(data.philo[0].start_time, 3);
	free(data.philo[0].start_time);
	i = 0;
	while (i < data.size)
	{
		pthread_mutex_destroy(&(data.philo[i].last_eat.mutex));
		pthread_mutex_destroy(&(data.philo[i].nb_eat.mutex));
		i++;
	}
	free(data.philo);
}
