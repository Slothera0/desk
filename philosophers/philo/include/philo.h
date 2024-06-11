/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:31:21 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 16:51:05 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/types.h>

# define TRUE 1
# define FALSE 0
# define WAIT_TIME 1
# define MAX_PHILO 20001

typedef struct s_lock
{
	size_t			status;
	pthread_mutex_t	mutex;
}					t_lock;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	int				eat_time;
	int				sleep_time;
	t_lock			last_eat;
	t_lock			nb_eat;
	t_lock			*l_fork;
	t_lock			*r_fork;
	t_lock			*start_time;
	t_lock			*stop;
	t_lock			*print;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	size_t			dead_time;
	ssize_t			nb_eat;
	size_t			size;
}					t_data;

void				init_philo(t_data *data, int argc, char **argv);
int					create_thread(t_data data);
void				*routine(void *philo);
void				monitoring(t_data data);
void				end_thread(t_data data);
int					stop_test(t_lock *stop);
void				ft_usleep_stop(size_t time, size_t start_time,
						t_lock *stop);
int					*error_arg(char *str);
int					ft_atoi(const char *nptr);
void				ft_usleep(size_t time, size_t start_time);
size_t				get_time(size_t start);
void				take_fork(t_philo *philo);
void				drop_fork(t_philo *philo);
void				clear_data(t_data data);

#endif