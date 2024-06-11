/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:36:26 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 16:50:19 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int		*parse_arg(int argc, char **argv);
int		init_mutex_p(t_lock *mutex_p1, t_lock *mutex_p2);
void	init_mutex(t_lock **fork, t_lock **mutex_g, int size);
void	set_value(t_philo *philo, t_lock *fork, t_lock *mutex_g, int *arg_val);
void	free_init(t_philo **philo, int *arg_value, \
	t_lock *mutex_g, t_lock *fork);
void	destroy_mutex_p(t_philo *philo, int size);

void	init_philo(t_data *data, int argc, char **argv)
{
	t_lock	*mutex_g;
	t_lock	*fork;
	int		*arg_value;

	arg_value = parse_arg(argc, argv);
	if (!arg_value)
		return ;
	data->philo = malloc(sizeof(t_philo) * arg_value[0]);
	if (!(data->philo) && !error_arg("malloc error\n"))
	{
		free(arg_value);
		return ;
	}
	data->size = arg_value[0];
	data->dead_time = arg_value[1];
	data->nb_eat = arg_value[4];
	init_mutex(&fork, &mutex_g, arg_value[0]);
	if ((!mutex_g || !fork) && !error_arg("Error with pthread_mutex\n"))
	{
		free_init(&(data->philo), arg_value, mutex_g, fork);
		return ;
	}
	set_value(data->philo, fork, mutex_g, arg_value);
	free(arg_value);
	return ;
}

int	*parse_arg(int argc, char **argv)
{
	int	*arg_value;

	if (argc < 5 || argc > 6)
		return (error_arg("wrong number of arguments\n"));
	arg_value = malloc(sizeof(int) * 5);
	if (!arg_value)
		return (error_arg("malloc error\n"));
	arg_value[0] = ft_atoi(argv[1]);
	arg_value[1] = ft_atoi(argv[2]);
	arg_value[2] = ft_atoi(argv[3]);
	arg_value[3] = ft_atoi(argv[4]);
	arg_value[4] = -1;
	if (argc == 6)
		arg_value[4] = ft_atoi(argv[5]);
	if (arg_value[0] == -2 || arg_value[1] == -2 || arg_value[2] == -2
		|| arg_value[3] == -2 || arg_value[4] == -2 || arg_value[0] == 0
		|| arg_value[0] >= MAX_PHILO)
	{
		if (arg_value[0] == 0)
			return (free(arg_value), NULL);
		if (arg_value[0] >= MAX_PHILO)
			return (free(arg_value), error_arg("Enter fewer philosophers\n"));
		return (free(arg_value), error_arg("Error with arg value\n"));
	}
	return (arg_value);
}

void	set_value(t_philo *philo, t_lock *fork, t_lock *mutex_g, int *arg_val)
{
	int	i;

	i = 0;
	while (i < arg_val[0])
	{
		philo[i].id = i + 1;
		philo[i].eat_time = arg_val[2];
		philo[i].sleep_time = arg_val[3];
		philo[i].l_fork = &(fork[i]);
		if (i < arg_val[0] - 1)
			philo[i].r_fork = &(fork[i + 1]);
		else
			philo[i].r_fork = &(fork[0]);
		if (init_mutex_p(&(philo[i].nb_eat), &(philo[i].last_eat)))
		{
			destroy_mutex_p(philo, i);
			free_init(&philo, NULL, mutex_g, fork);
			error_arg("Error with pthread_mutex\n");
			return ;
		}
		philo[i].start_time = &(mutex_g[0]);
		philo[i].stop = &(mutex_g[1]);
		philo[i].print = &(mutex_g[2]);
		i++;
	}
}

void	free_init(t_philo **philo, int *arg_value, \
	t_lock *mutex_g, t_lock *fork)
{
	free(*philo);
	free(fork);
	if (arg_value)
		free(arg_value);
	*philo = NULL;
	if (mutex_g)
		free(mutex_g);
	if (fork)
		free(fork);
}
