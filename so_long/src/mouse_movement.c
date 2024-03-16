/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 04:29:49 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/16 18:26:36 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void	clear_mouse_pos(t_data *data, t_mouse *mouse);
static void	apply_texture_mouse(t_data *data, t_mouse *mouse);
void		change_sprit_mouse_left(t_data *data, t_mouse *mouse);
void		change_sprit_mouse_right(t_data *data, t_mouse *mouse);

int	mouse_movement(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mouse_nbr)
	{
		move_mouse(data, i);
		i++;
	}
	return (0);
}

int	move_mouse(t_data *data, int i)
{
	clear_mouse_pos(data, &(MOUSE[i])); // refaire
	mlx_destroy_image(data->mlx, MOUSE[i].mouse[data->natural_move % 2].img);
	if (MOUSE[i].look == RIGHT && (MOUSE[i].pos[0] % \
		BLOCK > BLOCK - MWALK - MOUSE_W || (data->map[MOUSE[i].pos[1] / BLOCK] \
		[MOUSE[i].pos[0] / BLOCK + 1] != '1' && data->map[MOUSE[i].pos[1] / \
		BLOCK + 1][MOUSE[i].pos[0] / BLOCK + 1] != '0')))
	{
		MOUSE[i].pos[0] += MWALK;
		change_sprit_mouse_right(data, &(MOUSE[i]));
	}
	else if (MOUSE[i].pos[0] % BLOCK < MWALK ||
		(data->map[MOUSE[i].pos[1] / BLOCK][MOUSE[i].pos[0] / BLOCK - 1] != '1' \
		&& data->map[MOUSE[i].pos[1] / BLOCK + 1][MOUSE[i].pos[0] / BLOCK - 1] != '0'))
	{
		data->pos[0] -= WALK;
		change_sprit_mouse_left(data, &(MOUSE[i]));
	}
	else
	{
		MOUSE[i].pos[0] += MWALK;
		change_sprit_mouse_right(data, &(MOUSE[i]));
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		MOUSE[i].mouse[data->natural_move % 2].img, MOUSE[i].pos[0], MOUSE[i].pos[1]);
	return (0);
}

static void	clear_mouse_pos(t_data *data, t_mouse *mouse)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (MPOS_X \
		/ BLOCK) * BLOCK, (MPOS_Y / BLOCK) * BLOCK);
	if ((MPOS_X / BLOCK) * BLOCK != ((MPOS_X + MOUSE_W) / BLOCK) * BLOCK)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (( MPOS_X \
			/ BLOCK) + 1) * BLOCK, (MPOS_Y / BLOCK) * BLOCK);
	}
	if (MPOS_Y / BLOCK * BLOCK != (MPOS_Y + MOUSE_H - 1) / BLOCK * BLOCK)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (MPOS_X \
			/ BLOCK) * BLOCK, (MPOS_Y / BLOCK + 1) * BLOCK);
	}
	if (MPOS_X / BLOCK * BLOCK != (MPOS_X + MOUSE_W) / BLOCK * BLOCK \
		&& MPOS_Y / BLOCK * BLOCK \
		!= (MPOS_Y + MOUSE_H - 1) / BLOCK * BLOCK)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, BACK, (MPOS_X \
			/ BLOCK + 1) * BLOCK, (MPOS_Y / BLOCK + 1) * BLOCK);
	}
}

void	change_sprit_mouse_left(t_data *data, t_mouse *mouse)
{
	char	*path_char;
	char	*temp;
	int		img_size[2];

	if (mouse->look == LEFT && mouse->move_side[0] != '3')
		mouse->move_side[0]++;
	else
		mouse->move_side[0] = '1';
	mouse->look = LEFT;
	temp = ft_strjoin("./texture_2/mouse_run", mouse->move_side);
	path_char = ft_strjoin(temp, "_left.xpm");
	free(temp);
	mouse->mouse[data->natural_move % 2].img = mlx_xpm_file_to_image(data->mlx, \
		path_char, &(img_size[0]), &(img_size[0]));
	free(path_char);
	if (!mouse->mouse[data->natural_move % 2].img)
		exit_during_game(data); // rajouter mouse dans erreur
	apply_texture_mouse(data, mouse);
}

void	change_sprit_mouse_right(t_data *data, t_mouse *mouse)
{
	char	*path_char;
	char	*temp;
	int		img_size[2];

	if (mouse->look == RIGHT && mouse->move_side[0] != '3')
		mouse->move_side[0]++;
	else
		mouse->move_side[0] = '1';
	mouse->look = RIGHT;
	temp = ft_strjoin("./texture_2/mouse_run", mouse->move_side);
	path_char = ft_strjoin(temp, ".xpm");
	free(temp);
	mouse->mouse[data->natural_move % 2].img = mlx_xpm_file_to_image(data->mlx, \
		path_char, &(img_size[0]), &(img_size[0]));
	free(path_char);
	if (!mouse->mouse[data->natural_move % 2].img)
		exit_during_game(data); // rajouter mouse dans erreur
	apply_texture_mouse(data, mouse);
}

static void	apply_texture_mouse(t_data *data, t_mouse *mouse)
{
	mouse->mouse[data->natural_move % 2].addr = \
		mlx_get_data_addr(mouse->mouse[data->natural_move % 2].img, \
		&mouse->mouse[data->natural_move % 2].bits_per_pixel, \
		&mouse->mouse[data->natural_move % 2].line_length, \
		&mouse->mouse[data->natural_move % 2].endian);
	replace_pixel(&(mouse->mouse[data->natural_move % 2]), \
		&data->texture.background, mouse->pos);
}