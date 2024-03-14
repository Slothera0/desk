/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 04:29:49 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 06:48:34 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

/*
int	move_mouse_right(t_data *data, int i)
{
	if (data->map[data->mouse_pos_y[i] / BLOCK][(data->mouse_POS_Y[i] + 1) / BLOCK] == '1')
		return (0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.background, data->mouse_POS_Y[i] / BLOCK * BLOCK, data->mouse_pos_y[i] / BLOCK * BLOCK);
	if (data->mouse_POS_Y[i] % 64 >= 32)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.background, (data->mouse_POS_Y[i] / BLOCK + 1) * BLOCK, data->mouse_pos_y[i] / BLOCK * BLOCK);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.mouse, (data->mouse_POS_Y[i] + 1) + 16, data->mouse_pos_y[i] + 46);
	data->mouse_POS_Y[i]++;
	return (0);
}

int	move_mouse_left(t_data *data, int i)
{
	if (data->map[data->mouse_pos_y[i] / BLOCK][(data->mouse_POS_Y[i] - 1) / BLOCK] == '1')
		return (0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.background, data->mouse_POS_Y[i] / BLOCK * BLOCK, data->mouse_pos_y[i] / BLOCK * BLOCK);
	if (data->mouse_POS_Y[i] % 64 >= 32)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.background, (data->mouse_POS_Y[i] / BLOCK + 1) * BLOCK, data->mouse_pos_y[i] / BLOCK * BLOCK);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.mouse, data->mouse_POS_Y[i] - 1 + 16, data->mouse_pos_y[i] + 46);
	data->mouse_POS_Y[i]--;
	return (0);
}

int	move_mouse(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mouse_nbr)
	{
		if (data->map[data->mouse_pos_y[i] / BLOCK][(data->mouse_POS_Y[i] / BLOCK) + 1] == '0' && data->mouse_look_left == 0)
		{
			data->mouse_look_left = 0;
			move_mouse_right(data, i);
		}
		else if (data->map[data->mouse_pos_y[i] / BLOCK][data->mouse_POS_Y[i] / BLOCK - 1] == '0')
		{
			data->mouse_look_left = 1;
			move_mouse_left(data, i);
		}
		else
		{
			data->mouse_look_left = 0;
			move_mouse_right(data, i);
		}
		i++;
	}
	return (0);
}
*/


