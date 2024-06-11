/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:45:49 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 15:57:18 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

size_t	get_time(size_t start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start);
}

void	ft_usleep(size_t time, size_t start_time)
{
	size_t	start;

	start = get_time(start_time);
	while ((get_time(start_time) - start) < time)
		usleep(500);
}

void	ft_usleep_stop(size_t time, size_t start_time, t_lock *stop)
{
	size_t	start;

	start = get_time(start_time);
	while ((get_time(start_time) - start) < time)
	{
		if (!stop_test(stop))
			return ;
		usleep(500);
	}
}
