/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claim_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:54:32 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/20 13:05:18 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	claim_coin(t_data *data)
{
	if (data->map[data->pos[1] / BLC][data->pos[0] / BLC] == 'C')
	{
		data->map[data->pos[1] / BLC][data->pos[0] / BLC] = '0';
		data->total_coin--;
	}
	if ((data->pos[0] / BLC) * BLC != ((data->pos[0] + DRG_W) / BLC) * BLC \
		&& data->map[data->pos[1] / BLC][data->pos[0] / BLC + 1] == 'C')
	{
		data->map[data->pos[1] / BLC][data->pos[0] / BLC + 1] = '0';
		data->total_coin--;
	}
	if (data->pos[1] / BLC * BLC != (data->pos[1] + DRG_H - 1) / BLC * BLC \
		&& data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC] == 'C')
	{
		data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC] = '0';
		data->total_coin--;
	}
	if ((data->pos[0] / BLC * BLC != (data->pos[0] + DRG_W) / BLC * BLC \
		&& data->pos[1] / BLC * BLC != (data->pos[1] + DRG_H - 1) / BLC * BLC) \
		&& data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC + 1] == 'C')
	{
		data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC + 1] = '0';
		data->total_coin--;
	}
}

void	take_portail(t_data *data)
{
	if (data->total_coin != 0)
		return ;
	if (data->map[data->pos[1] / BLC][data->pos[0] / BLC] == 'P')
		mlx_loop_end(data->mlx);
	if ((data->pos[0] / BLC) * BLC != ((data->pos[0] + DRG_W) / BLC) * BLC \
		&& data->map[data->pos[1] / BLC][data->pos[0] / BLC + 1] == 'C')
		mlx_loop_end(data->mlx);
	if (data->pos[1] / BLC * BLC != (data->pos[1] + DRG_H - 1) / BLC * BLC \
		&& data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC] == 'C')
		mlx_loop_end(data->mlx);
	if ((data->pos[0] / BLC * BLC != (data->pos[0] + DRG_W) / BLC * BLC \
		&& data->pos[1] / BLC * BLC != (data->pos[1] + DRG_H - 1) / BLC * BLC) \
		&& data->map[data->pos[1] / BLC + 1][data->pos[0] / BLC + 1] == 'C')
		mlx_loop_end(data->mlx);
}
