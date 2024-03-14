/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drg_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:46:37 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 07:02:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

int	move_dragon(t_data *data, int side)
{
	if (((data->map[POS_Y / BLOCK][POS_X / BLOCK + 1] == '1' \
		|| data->map[(POS_Y + DRG_H - 1) / BLOCK][POS_X / BLOCK + 1] == '1') \
		&& (side == RIGHT && POS_X % BLOCK > BLOCK - WALK - DRG_W)) \
		|| ((data->map[POS_Y / BLOCK][POS_X / BLOCK - 1] == '1' \
		|| data->map[(POS_Y + DRG_H - 1) / BLOCK][POS_X / BLOCK - 1] == '1') \
		&& (side == LEFT && POS_X % BLOCK < WALK)))
		return (0);
	clear_pos(data);
	if (side == RIGHT)
	{
		data->pos[0] += WALK;
		change_sprit_drg_right(data);
	}
	else
	{
		data->pos[0] -= WALK;
		change_sprit_drg_left(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->texture.dragon[TEXT_USE].img, POS_X, POS_Y);
	return (0);
}

int	fly_char(t_data *data)
{
	if ((data->map[POS_Y / BLOCK - 1][POS_X / BLOCK] == '1' \
		|| data->map[POS_Y / BLOCK - 1][(POS_X + DRG_W - 1) \
		/ BLOCK] == '1') && POS_Y % BLOCK < FLY)
		return (0);
	clear_pos(data);
	data->pos[1] -= FLY;
	change_sprit_drg_fly(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->texture.dragon[TEXT_USE].img, POS_X, POS_Y);
	return (0);
}

int	do_gravity(t_data *data)
{
	if ((data->map[POS_Y / BLOCK + 1][POS_X / BLOCK] == '1' \
		|| data->map[POS_Y / BLOCK + 1][(POS_X + DRG_W - 1) \
		/ BLOCK] == '1') && POS_Y % BLOCK == BLOCK - DRG_H)
		return (0);
	clear_pos(data);
	if ((data->map[(POS_Y) / BLOCK + 1][POS_X / BLOCK] == '1' \
		|| data->map[POS_Y / BLOCK + 1][(POS_X + DRG_W) \
		/ BLOCK] == '1') && (POS_Y + DRG_H) % BLOCK > BLOCK - WALK)
		POS_Y += BLOCK - (POS_Y + DRG_H) % BLOCK;
	else
		data->pos[1] += WALK;
	change_sprit_drg_gravity(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->texture.dragon[TEXT_USE].img, (POS_X), (POS_Y));
	return (0);
}

void	clear_pos(t_data *data)
{
	if (data->map[POS_Y / BLOCK][POS_X / BLOCK] == 'C')
	{
		data->map[POS_Y / BLOCK][POS_X / BLOCK] = '0';
		data->total_coin--;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (POS_X \
		/ BLOCK) * BLOCK, (POS_Y / BLOCK) * BLOCK);
	if ((POS_X / BLOCK) * BLOCK != ((POS_X + DRG_W) / BLOCK) * BLOCK)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, ((POS_X \
			/ BLOCK) + 1) * BLOCK, (POS_Y / BLOCK) * BLOCK);
	}
	if (POS_Y / BLOCK * BLOCK != (POS_Y + DRG_H - 1) / BLOCK * BLOCK)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (POS_X \
			/ BLOCK) * BLOCK, (POS_Y / BLOCK + 1) * BLOCK);
	}
	if (POS_X / BLOCK * BLOCK != (POS_X + DRG_W) / BLOCK * BLOCK \
		&& POS_Y / BLOCK * BLOCK \
		!= (POS_Y + DRG_H - 1) / BLOCK * BLOCK)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (POS_X \
			/ BLOCK + 1) * BLOCK, (POS_Y / BLOCK + 1) * BLOCK);
	}
}
