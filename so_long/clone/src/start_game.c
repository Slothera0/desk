/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:55:03 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:24:18 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static int	routine(t_data *data);
static int	input(int keysym, t_data *data);
static int	close_win(t_data *data);

int	start_game(t_data *data)
{
	data->drg_look = RIGHT;
	data->drg_move_side[0] = '1';
	data->drg_move_side[1] = '\0';
	data->do_movement = 0;
	data->pmv = 0;
	data->nmv = 0;
	data->bool_portail = 0;
	mlx_loop_hook(data->mlx, &routine, data);
	mlx_hook(data->mlx_win, 2, (1L << 0), &input, data);
	mlx_hook(data->mlx_win, 17, (1L << 0), &close_win, data);
	mlx_loop(data->mlx);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->texture.background.img);
	mlx_destroy_image(data->mlx, data->texture.dragon[0].img);
	mlx_destroy_image(data->mlx, data->texture.dragon[1].img);
	mlx_destroy_image(data->mlx, data->texture.wall);
	mlx_destroy_image(data->mlx, data->texture.portail.img);
	mlx_destroy_image(data->mlx, data->texture.diamond.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (0);
}

static int	routine(t_data *data)
{
	if (data->total_coin == 0 && data->bool_portail == 0)
	{
		put_all_block('P', data->texture.portail.img, data);
		data->bool_portail = 1;
	}
	if (data->do_movement == 20000)
	{
		data->nmv++;
		do_gravity(data);
		data->do_movement = 0;
	}
	data->do_movement++;
	return (0);
}

static int	input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keysym == XK_d)
		move_dragon(data, RIGHT);
	else if (keysym == XK_a)
		move_dragon(data, LEFT);
	else if (keysym == XK_w)
		fly_char(data);
	return (0);
}

static int	close_win(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	print_move(t_data *data)
{
	if (data->pmv < 0)
		return (0);
	if (ft_putstr_fd("Move : ", 1) < 0)
		exit_during_game(data);
	if (ft_putnbr_fd(data->pmv, 1) < 0)
		exit_during_game(data);
	if (ft_putchar_fd('\n', 1) < 0)
		exit_during_game(data);
	return (1);
}
