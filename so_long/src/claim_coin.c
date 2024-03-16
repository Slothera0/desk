/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claim_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:54:32 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 08:25:55 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	claim_coin(t_data *data)
{
	if (data->map[POS_Y / BLOCK][POS_X / BLOCK] == 'C')
	{
		data->map[POS_Y / BLOCK][POS_X / BLOCK] = '0';
		data->total_coin--;
	}
	if ((POS_X / BLOCK) * BLOCK != ((POS_X + DRG_W) / BLOCK) * BLOCK \
		&& data->map[POS_Y / BLOCK][POS_X / BLOCK + 1] == 'C')
	{
		data->map[POS_Y / BLOCK][POS_X / BLOCK + 1] = '0';
		data->total_coin--;
	}
	if (POS_Y / BLOCK * BLOCK != (POS_Y + DRG_H - 1) / BLOCK * BLOCK \
		&& data->map[POS_Y / BLOCK + 1][POS_X / BLOCK] == 'C')
	{
		data->map[POS_Y / BLOCK + 1][POS_X / BLOCK] = '0';
		data->total_coin--;
	}
	if ((POS_X / BLOCK * BLOCK != (POS_X + DRG_W) / BLOCK * BLOCK \
		&& POS_Y / BLOCK * BLOCK != (POS_Y + DRG_H - 1) / BLOCK * BLOCK) \
		&& data->map[POS_Y / BLOCK + 1][POS_X / BLOCK + 1] == 'C')
	{
		data->map[POS_Y / BLOCK + 1][POS_X / BLOCK + 1] = '0';
		data->total_coin--;
	}
}

void	take_portail(t_data *data)
{
	if (data->map[POS_Y / BLOCK][POS_X / BLOCK] == 'P')
		mlx_loop_end(data->mlx);
	if ((POS_X / BLOCK) * BLOCK != ((POS_X + DRG_W) / BLOCK) * BLOCK \
		&& data->map[POS_Y / BLOCK][POS_X / BLOCK + 1] == 'C')
		mlx_loop_end(data->mlx);
	if (POS_Y / BLOCK * BLOCK != (POS_Y + DRG_H - 1) / BLOCK * BLOCK \
		&& data->map[POS_Y / BLOCK + 1][POS_X / BLOCK] == 'C')
		mlx_loop_end(data->mlx);
	if ((POS_X / BLOCK * BLOCK != (POS_X + DRG_W) / BLOCK * BLOCK \
		&& POS_Y / BLOCK * BLOCK != (POS_Y + DRG_H - 1) / BLOCK * BLOCK) \
		&& data->map[POS_Y / BLOCK + 1][POS_X / BLOCK + 1] == 'C')
		mlx_loop_end(data->mlx);
}
