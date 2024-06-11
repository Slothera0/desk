/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:49:12 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 16:19:25 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int		death_test(t_philo *philo, size_t dead_time);
int		finish_eat(t_lock *stop_mutex, size_t all_eat, size_t size);
size_t	eat_test(t_philo *philo, ssize_t nb_eat);
void	die_message(t_philo philo);

void	monitoring(t_data data)
{
	size_t	i;
	size_t	all_eat;
	int		stop;

	stop = 0;
	while (stop == 0)
	{
		i = 0;
		all_eat = 0;
		while (i < data.size)
		{
			stop = death_test(&(data.philo[i]), data.dead_time);
			if (stop == 1)
			{
				die_message(data.philo[i]);
				return ;
			}
			all_eat += eat_test(&(data.philo[i]), data.nb_eat);
			i++;
		}
		stop = finish_eat(data.philo[0].stop, all_eat, data.size);
		ft_usleep(5, data.philo[0].start_time->status);
	}
}

int	death_test(t_philo *philo, size_t dead_time)
{
	int	stop;

	stop = 0;
	pthread_mutex_lock(&(philo->last_eat.mutex));
	if (philo->last_eat.status + dead_time \
		< get_time(philo->start_time->status))
	{
		pthread_mutex_lock(&(philo->stop->mutex));
		philo->stop->status = TRUE;
		pthread_mutex_unlock(&(philo->stop->mutex));
		stop = 1;
	}
	pthread_mutex_unlock(&(philo->last_eat.mutex));
	return (stop);
}

size_t	eat_test(t_philo *philo, ssize_t nb_eat)
{
	size_t	finish_eat;

	finish_eat = 0;
	if (nb_eat >= 0)
	{
		pthread_mutex_lock(&(philo->nb_eat.mutex));
		if (philo->nb_eat.status >= (size_t)nb_eat)
			finish_eat++;
		pthread_mutex_unlock(&(philo->nb_eat.mutex));
	}
	return (finish_eat);
}

int	finish_eat(t_lock *stop_mutex, size_t all_eat, size_t size)
{
	int	stop;

	stop = 0;
	if (all_eat == size)
	{
		pthread_mutex_lock(&(stop_mutex->mutex));
		stop_mutex->status = TRUE;
		pthread_mutex_unlock(&(stop_mutex->mutex));
		stop = 1;
	}
	return (stop);
}

void	die_message(t_philo philo)
{
	pthread_mutex_lock(&(philo.print->mutex));
	printf("%zu %lu died\n", get_time(philo.start_time->status), philo.id);
	pthread_mutex_unlock(&(philo.print->mutex));
}
