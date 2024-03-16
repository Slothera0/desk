/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:42:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/16 18:39:51 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void	set_mouse_data(t_mouse *mouse, t_data *data);
static t_mouse	*mouse_append(t_mouse *mouse, int x, int y);

void	init_mouse(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->mouse = malloc(sizeof(t_mouse));
	if (!data->mouse)
		mouse_error();
	data->mouse->pos[0] = -1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
				data->mouse = mouse_append(data->mouse, j, i);
			j++;
		}
		i++;
	}
	i = 0;
	while (data->mouse[i].pos[0] != -1)
		set_mouse_data(&(data->mouse[i++]), data);
	data->mouse_nbr = i;
}

static void	set_mouse_data(t_mouse *mouse, t_data *data)
{
	char	*mouse_path;
	int		size[2];
	
	mouse->look = RIGHT;
	mouse->move_side[0] = '1';
	mouse->move_side[1] = '\0';
	mouse->mouse[0].id = 2;
	mouse->mouse[1].id = 2;
	mouse_path = ft_strdup("./texture_2/mouse_run1.xpm");
	if (!mouse_path)
		mouse_error(); // free + message + ratio
	mouse->mouse[0].img = mlx_xpm_file_to_image(data->mlx, mouse_path, &size[0], &size[1]);
	mouse->mouse[1].img = mlx_xpm_file_to_image(data->mlx, mouse_path, &size[0], &size[1]);
	if (!mouse->mouse[0].img || !mouse->mouse[1].img)
		mouse_error();
	mouse->mouse[0].addr = mlx_get_data_addr(mouse->mouse[0].img, \
		&(mouse->mouse[0].bits_per_pixel), &(mouse->mouse[0].line_length), \
		&(mouse->mouse[0].endian));
	printf("test %d %d\n", mouse->pos[0], mouse->pos[1]);
	replace_pixel(&(mouse->mouse[0]), BACK, mouse->pos);
	mlx_put_image_to_window(data->mlx, data->mlx_win, mouse->mouse[0].img, mouse->pos[0], mouse->pos[1]);
}

static t_mouse	*mouse_append(t_mouse *mouse, int x, int y)
{
	t_mouse	*new;
	int		i;

	i = 0;
	while (mouse[i].pos[0] != -1)
		i++;
	new = malloc(sizeof(t_mouse) * (i + 2));
	if (!new)
	{
		free(mouse);
		return (NULL);
	}
	i = 0;
	while (mouse[i].pos[0] != -1)
	{
		new[i].pos[0] = mouse[i].pos[0];
		new[i].pos[1] = mouse[i].pos[1];
		i++;
	}
	new[i].pos[0] = x * BLOCK;
	new[i].pos[1] = y * BLOCK;
	new[i + 1].pos[0] = -1;
	free(mouse);
	return (new);
}
