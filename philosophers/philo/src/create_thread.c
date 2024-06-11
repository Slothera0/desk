/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:36:34 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 16:02:09 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data data)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&(data.philo[0].start_time->mutex));
	while (i < data.size)
	{
		if (pthread_create(&(data.philo[i].thread), \
			NULL, routine, &(data.philo[i])) != 0)
		{
			error_arg("Error with pthread_create()\n");
			return (1);
		}
		i++;
	}
	data.philo[0].start_time->status = get_time(0);
	pthread_mutex_unlock(&(data.philo[0].start_time->mutex));
	return (0);
}
