/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drg_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:46:37 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:46:27 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	move_dragon(t_data *data, int side)
{
	if (((data->map[data->pos[1] / BLC][data->pos[0] / BLC + 1] == '1' \
		|| data->map[(data->pos[1] + DRG_H - 1) / BLC] \
		[data->pos[0] / BLC + 1] == '1') \
		&& (side == RIGHT && data->pos[0] % BLC > BLC - WALK - DRG_W)) \
		|| ((data->map[data->pos[1] / BLC][data->pos[0] / BLC - 1] == '1' \
		|| data->map[(data->pos[1] + DRG_H - 1) / BLC] \
		[data->pos[0] / BLC - 1] == '1') \
		&& (side == LEFT && data->pos[0] % BLC < WALK)))
		return (0);
	data->pmv++;
	clear_pos(data);
	mlx_destroy_image(data->mlx, \
		data->texture.dragon[(data->pmv + data->nmv) % 2].img);
	if (side == RIGHT)
		data->pos[0] += WALK;
	if (side == RIGHT)
		change_sprit_drg_right(data);
	if (side == LEFT)
		data->pos[0] -= WALK;
	if (side == LEFT)
		change_sprit_drg_left(data);
	print_move(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture.dragon \
		[(data->pmv + data->nmv) % 2].img, data->pos[0], data->pos[1]);
	return (0);
}

int	fly_char(t_data *data)
{
	if ((data->map[data->pos[1] / BLC - 1][data->pos[0] / BLC] == '1' \
		|| data->map[data->pos[1] / BLC - 1][(data->pos[0] + DRG_W - 1) \
		/ BLC] == '1') && data->pos[1] % BLC < FLY)
		return (0);
	data->pmv++;
	clear_pos(data);
	mlx_destroy_image(data->mlx, \
		data->texture.dragon[(data->pmv + data->nmv) % 2].img);
	data->pos[1] -= FLY;
	change_sprit_drg_fly(data);
	print_move(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->texture.dragon[(data->pmv + data->nmv) % 2].img, \
		data->pos[0], data->pos[1]);
	return (0);
}

int	do_gravity(t_data *data)
{
	if ((data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC] == '1' \
		|| data->map[data->pos[1] / BLC + 1][(data->pos[0] + DRG_W - 1) \
		/ BLC] == '1') && data->pos[1] % BLC == BLC - DRG_H)
		return (0);
	clear_pos(data);
	mlx_destroy_image(data->mlx, \
		data->texture.dragon[(data->pmv + data->nmv) % 2].img);
	if ((data->map[(data->pos[1]) / BLC + 1][data->pos[0] / BLC] == '1' \
		|| data->map[data->pos[1] / BLC + 1][(data->pos[0] + DRG_W) \
		/ BLC] == '1') && (data->pos[1] + DRG_H) % BLC > BLC - WALK)
		data->pos[1] += BLC - (data->pos[1] + DRG_H) % BLC;
	else
		data->pos[1] += WALK;
	change_sprit_drg_gravity(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->texture.dragon[(data->pmv + data->nmv) % 2].img, \
		(data->pos[0]), (data->pos[1]));
	return (0);
}

void	clear_pos(t_data *data)
{
	claim_coin(data);
	take_portail(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->texture.background.img, (data->pos[0] / BLC) * BLC, \
		(data->pos[1] / BLC) * BLC);
	if ((data->pos[0] / BLC) * BLC != ((data->pos[0] + DRG_W) / BLC) * BLC)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->texture.background.img, ((data->pos[0] / BLC) + 1) * BLC, \
			(data->pos[1] / BLC) * BLC);
	}
	if (data->pos[1] / BLC * BLC != (data->pos[1] + DRG_H - 1) / BLC * BLC)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->texture.background.img, (data->pos[0] / BLC) * BLC, \
			(data->pos[1] / BLC + 1) * BLC);
	}
	if (data->pos[0] / BLC * BLC != (data->pos[0] + DRG_W) / BLC * BLC \
		&& data->pos[1] / BLC * BLC \
		!= (data->pos[1] + DRG_H - 1) / BLC * BLC)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->texture.background.img, (data->pos[0] / BLC + 1) * BLC, \
			(data->pos[1] / BLC + 1) * BLC);
	}
}
