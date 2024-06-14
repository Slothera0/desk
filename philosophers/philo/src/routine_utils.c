/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:42:36 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/14 14:47:25 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	take_one_fork(t_lock *fork, t_philo *philo);

void	take_fork(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!stop_test(philo->stop))
			return ;
		i += take_one_fork(philo->l_fork, philo);
		if (!stop_test(philo->stop))
			return ;
		i += take_one_fork(philo->r_fork, philo);
		if (!stop_test(philo->stop))
			return ;
		if (i < 2)
			ft_usleep(WAIT_TIME, philo->start_time->status);
	}
}

int	take_one_fork(t_lock *fork, t_philo *philo)
{
	int	taken;

	taken = 0;
	pthread_mutex_lock(&(fork->mutex));
	if (fork->status == TRUE)
	{
		taken++;
		fork->status = FALSE;
		pthread_mutex_lock(&(philo->print->mutex));
		if (stop_test(philo->stop))
			printf("%zu %zu has taken a fork\n", \
				get_time(philo->start_time->status), philo->id);
		pthread_mutex_unlock(&(philo->print->mutex));
	}
	pthread_mutex_unlock(&(fork->mutex));
	return (taken);
}

void	drop_fork(t_philo *philo)
{
	if (!stop_test(philo->stop))
		return ;
	pthread_mutex_lock(&(philo->l_fork->mutex));
	philo->l_fork->status = TRUE;
	pthread_mutex_unlock(&(philo->l_fork->mutex));
	pthread_mutex_lock(&(philo->r_fork->mutex));
	philo->r_fork->status = TRUE;
	pthread_mutex_unlock(&(philo->r_fork->mutex));
}
