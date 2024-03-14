/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drg_movement_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:47:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 06:51:44 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

void	change_sprit_drg_left(t_data *data)
{
	char	*path_char;
	char	*temp;
	int		img_size[2];

	if (data->drg_look == LEFT && data->drg_move_side[0] != '3')
		data->drg_move_side[0]++;
	else if (data->drg_look == LEFT && data->drg_move_side[0] == '3')
		data->drg_move_side[0] = '1';
	else
	{
		data->drg_look = LEFT;
		data->drg_move_side[0] = '1';
	}
	if (data->map[POS_Y / BLOCK + 1][POS_X / BLOCK] == '1' \
		&& POS_Y % BLOCK == BLOCK - DRG_H)
		temp = ft_strjoin("./texture_2/char_run", data->drg_move_side);
	else
		temp = ft_strjoin("./texture_2/char_fly", data->drg_move_side);
	path_char = ft_strjoin(temp, "_left.xpm");
	free(temp);
	data->texture.dragon[TEXT_USE].img = mlx_xpm_file_to_image(data->mlx, \
		path_char, &(img_size[0]), &(img_size[0]));
	free(path_char);
	apply_texture_drg(data);
}

void	change_sprit_drg_right(t_data *data)
{
	char	*path_char;
	char	*temp;
	int		img_size[2];

	if (data->drg_look == RIGHT && data->drg_move_side[0] != '3')
		data->drg_move_side[0]++;
	else if (data->drg_look == RIGHT && data->drg_move_side[0] == '3')
		data->drg_move_side[0] = '1';
	else
	{
		data->drg_look = RIGHT;
		data->drg_move_side[0] = '1';
	}
	if (data->map[POS_Y / BLOCK + 1][POS_X / BLOCK] == '1' \
		&& POS_Y % BLOCK == BLOCK - DRG_H)
		temp = ft_strjoin("./texture_2/char_run", data->drg_move_side);
	else
		temp = ft_strjoin("./texture_2/char_fly", data->drg_move_side);
	path_char = ft_strjoin(temp, ".xpm");
	free(temp);
	data->texture.dragon[TEXT_USE].img = mlx_xpm_file_to_image(data->mlx, \
		path_char, &(img_size[0]), &(img_size[0]));
	free(path_char);
	apply_texture_drg(data);
}

void	change_sprit_drg_fly(t_data *data)
{
	char	*path_char;
	char	*temp;
	int		img_size[2];

	if (data->drg_look == RIGHT && data->drg_move_side[0] == '3')
		data->drg_move_side[0] = '1';
	else if (data->drg_move_side[0] == '3')
		data->drg_move_side[0] = '1';
	else
		data->drg_move_side[0]++;
	temp = ft_strjoin("./texture_2/char_fly", data->drg_move_side);
	if (data->drg_look == RIGHT)
		path_char = ft_strjoin(temp, ".xpm");
	else
		path_char = ft_strjoin(temp, "_left.xpm");
	free(temp);
	data->texture.dragon[TEXT_USE].img = mlx_xpm_file_to_image(data->mlx, \
		path_char, &(img_size[0]), &(img_size[0]));
	free(path_char);
	apply_texture_drg(data);
}

void	change_sprit_drg_gravity(t_data *data)
{
	char	*path_char;
	char	*temp;
	int		img_size[2];
	
	temp = ft_strjoin("./texture_2/char_fly", data->drg_move_side);
	if (data->drg_look == RIGHT)
		path_char = ft_strjoin(temp, ".xpm");
	else
		path_char = ft_strjoin(temp, "_left.xpm");
	free(temp);
	data->texture.dragon[TEXT_USE].img = mlx_xpm_file_to_image(data->mlx, path_char, &(img_size[0]), &(img_size[0]));
	free(path_char);
	apply_texture_drg(data);
}

void	apply_texture_drg(t_data *data)
{
	data->texture.dragon[TEXT_USE].addr = \
		mlx_get_data_addr(data->texture.dragon[TEXT_USE].img, \
		&data->texture.dragon[TEXT_USE].bits_per_pixel, \
		&data->texture.dragon[TEXT_USE].line_length, \
		&data->texture.dragon[TEXT_USE].endian);
	replace_pixel(&data->texture.dragon[TEXT_USE], \
		&data->texture.background, data->pos);
}
