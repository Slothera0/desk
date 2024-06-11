/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 05:13:35 by arvoyer           #+#    #+#             */
/*   Updated: 2024/06/11 15:32:28 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_thread(t_data data)
{
	size_t	i;

	i = 0;
	while (i < data.size)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}
}
