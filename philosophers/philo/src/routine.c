/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:46:54 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/14 14:51:50 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int		stop_test(t_lock *dead);
void	eat(t_philo *philo);
void	sleep(t_philo *philo);
void	think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->start_time->mutex));
	pthread_mutex_unlock(&(philo->start_time->mutex));
	if (philo->id % 2 == 0)
	{
		think(philo);
		ft_usleep_stop(philo->eat_time, philo->start_time->status, philo->stop);
	}
	while (stop_test(philo->stop))
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
	return (arg);
}

int	stop_test(t_lock *stop)
{
	int	return_val;

	return_val = 1;
	pthread_mutex_lock(&(stop->mutex));
	if (stop->status == TRUE)
		return_val = 0;
	pthread_mutex_unlock(&(stop->mutex));
	return (return_val);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	if (!stop_test(philo->stop))
		return ;
	pthread_mutex_lock(&(philo->print->mutex));
	if (stop_test(philo->stop))
		printf("%zu %zu is eating\n", \
			get_time(philo->start_time->status), philo->id);
	pthread_mutex_unlock(&(philo->print->mutex));
	pthread_mutex_lock(&(philo->last_eat.mutex));
	philo->last_eat.status = get_time(philo->start_time->status);
	pthread_mutex_unlock(&(philo->last_eat.mutex));
	ft_usleep_stop(philo->eat_time, philo->start_time->status, philo->stop);
	pthread_mutex_lock(&(philo->nb_eat.mutex));
	philo->nb_eat.status++;
	pthread_mutex_unlock(&(philo->nb_eat.mutex));
	drop_fork(philo);
}

void	sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->print->mutex));
	if (stop_test(philo->stop))
		printf("%zu %zu is sleeping\n", \
			get_time(philo->start_time->status), philo->id);
	pthread_mutex_unlock(&(philo->print->mutex));
	if (stop_test(philo->stop))
		ft_usleep_stop(philo->sleep_time, \
			philo->start_time->status, philo->stop);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->print->mutex));
	if (stop_test(philo->stop))
		printf("%zu %zu is thinking\n", \
			get_time(philo->start_time->status), philo->id);
	pthread_mutex_unlock(&(philo->print->mutex));
}
