/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:40:58 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:41:06 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	replace_pixel(t_image *img, t_image *back, int pos[2])
{
	int	i;
	int	j;

	i = 0;
	while ((i < DRG_H && img->id == 1) || (i < BLC && img->id == 2))
	{
		j = 0;
		while ((j < DRG_W && img->id == 1) || (j < BLC && img->id == 2))
		{
			if (*(unsigned int *)(img->addr \
				+ (i * img->line_length + j * 4)) == GREEN)
			{
				*(unsigned int *)(img->addr + (i * img->line_length + j * 4)) \
					= *(unsigned int *)(back->addr + ((i + pos[1]) % BLC \
					* back->line_length + (j + pos[0]) % BLC * 4));
			}
			j++;
		}
		i++;
	}
}

void	set_all_addr(t_texture *texture)
{
	int	pos_temp[2];

	texture->background.addr = mlx_get_data_addr(texture->background.img, \
		&texture->background.bits_per_pixel, \
		&texture->background.line_length, &texture->background.endian);
	texture->dragon[0].addr = mlx_get_data_addr(texture->dragon[0].img, \
		&texture->dragon[0].bits_per_pixel, \
		&texture->dragon[0].line_length, &texture->dragon[0].endian);
	texture->diamond.addr = mlx_get_data_addr(texture->diamond.img, \
		&texture->diamond.bits_per_pixel, &texture->diamond.line_length, \
		&texture->diamond.endian);
	texture->portail.addr = mlx_get_data_addr(texture->portail.img, \
		&texture->portail.bits_per_pixel, &texture->portail.line_length, \
		&texture->portail.endian);
	texture->dragon[0].id = 1;
	texture->dragon[1].id = 1;
	texture->portail.id = 2;
	texture->diamond.id = 2;
	pos_temp[0] = 0;
	pos_temp[1] = 0;
	replace_pixel(&(texture->dragon[0]), &(texture->background), pos_temp);
	replace_pixel(&(texture->portail), &(texture->background), pos_temp);
	replace_pixel(&(texture->diamond), &(texture->background), pos_temp);
}
