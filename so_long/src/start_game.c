/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:55:03 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 06:51:54 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

static int	handle_no_event(t_data *data);
static int	handle_input(int keysym, t_data *data);

int	start_game(t_data *data)
{
	data->drg_look = RIGHT;
	data->drg_move_side[0] = '1';
	data->drg_move_side[1] = '\0';
	data->mouse_look = RIGHT;
	data->do_movement = 0;
	data->player_move = 0;
	data->natural_move = 0;
	
	mlx_loop_hook(data->mlx, &handle_no_event, data);
    mlx_hook(data->mlx_win, 2, (1L<<0), &handle_input, data);
	mlx_loop(data->mlx);
	return (0);	
}

static int	handle_no_event(t_data *data)
{
	if (data->do_movement % 1000 == 0)
	 {
	// 	move_mouse(data);
	 	if (data-> do_movement == 40000)
		{
			data->natural_move++;
			do_gravity(data);
			data->do_movement = 0;
			//printf("x:%d | y:%d\n", POS_X, POS_Y);
		}
	}
	data->do_movement++;
    return (0);
}

static int	handle_input(int keysym, t_data *data)
{
	data->player_move++;
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx, data->mlx_win);
	else if (keysym == XK_d)
	 	move_dragon(data, RIGHT);
	else if (keysym == XK_a)
	 	move_dragon(data, LEFT);
	else if (keysym == XK_w)
	 	fly_char(data);
    return (0);
}