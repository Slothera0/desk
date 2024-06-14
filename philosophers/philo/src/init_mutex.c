/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:19:16 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/14 14:44:07 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_lock	*init_fork(int size);
t_lock	*init_mutex_g(void);
void	destroy_mutex(t_lock *tab, int size);

void	init_mutex(t_lock **fork, t_lock **mutex_g, int size)
{
	(*mutex_g) = NULL;
	(*fork) = init_fork(size);
	if (!(*fork))
		return ;
	(*mutex_g) = init_mutex_g();
	if (!(*mutex_g))
	{
		destroy_mutex(*fork, size);
		free(*fork);
		(*fork) = NULL;
	}
}

t_lock	*init_fork(int size)
{
	t_lock	*fork;
	int		i;

	fork = malloc(sizeof(t_lock) * size);
	if (!fork)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&(fork[i].mutex), NULL) != 0)
		{
			destroy_mutex(fork, i);
			free(fork);
			return (NULL);
		}
		fork[i].status = TRUE;
		i++;
	}
	return (fork);
}

t_lock	*init_mutex_g(void)
{
	t_lock	*mutex_g;

	mutex_g = malloc(sizeof(t_lock) * 3);
	if (!mutex_g)
		return (NULL);
	if (pthread_mutex_init(&(mutex_g[0].mutex), NULL) != 0)
		return (free(mutex_g), NULL);
	mutex_g[0].status = 0;
	if (pthread_mutex_init(&(mutex_g[1].mutex), NULL) != 0)
	{
		destroy_mutex(mutex_g, 1);
		free(mutex_g);
		return (NULL);
	}
	mutex_g[1].status = FALSE;
	if (pthread_mutex_init(&(mutex_g[2].mutex), NULL) != 0)
	{
		destroy_mutex(mutex_g, 2);
		free(mutex_g);
		return (NULL);
	}
	mutex_g[2].status = 1;
	return (mutex_g);
}

int	init_mutex_p(t_lock *mutex_p1, t_lock *mutex_p2)
{
	if (pthread_mutex_init(&((*mutex_p1).mutex), NULL) != 0)
		return (1);
	(*mutex_p1).status = 0;
	if (pthread_mutex_init(&((*mutex_p2).mutex), NULL) != 0)
	{
		pthread_mutex_destroy(&((*mutex_p1).mutex));
		return (1);
	}
	(*mutex_p2).status = 0;
	return (0);
}
