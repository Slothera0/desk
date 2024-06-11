/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:29:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 16:01:36 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.philo = NULL;
	init_philo(&data, argc, argv);
	if (!(data.philo))
		return (1);
	if (create_thread(data))
		return (1);
	monitoring(data);
	end_thread(data);
	clear_data(data);
	return (0);
}
