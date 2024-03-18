/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:42:01 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:41:02 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void		*put_all_block(char c, void *texture, t_data *data);
static char	*set_path(char c);
static void	*set_texture(char *path, t_data *data);
static void	put_all_sprit(t_data *data);

void	print_map(t_data *data)
{
	int		x;
	int		y;

	data->total_coin = 0;
	y = ft_arraylen(data->map);
	x = ft_strlen(data->map[y - 1]);
	data->mlx_win = mlx_new_window(data->mlx, x * BLC, y * BLC, "so_long");
	if (!data->mlx_win)
		return ;
	data->texture.background.img = set_texture(set_path('0'), data);
	data->texture.wall = set_texture(set_path('1'), data);
	if (!data->texture.background.img || !data->texture.wall)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		if (data->texture.background.img)
			mlx_destroy_image(data->mlx, data->texture.background.img);
		if (data->texture.wall)
			mlx_destroy_image(data->mlx, data->texture.wall);
		data->mlx_win = NULL;
		return ;
	}
	put_all_block('0', data->texture.background.img, data);
	put_all_block('1', data->texture.wall, data);
	put_all_sprit(data);
}

void	*put_all_block(char c, void *texture, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == c || c == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					texture, j * BLC, i * BLC);
			if (data->map[i][j] == 'C' && c == 'C')
				data->total_coin++;
			j++;
		}
		i++;
	}
	return (texture);
}

static void	*set_texture(char *path, t_data *data)
{
	int		img_size[2];
	void	*img;

	if (!path)
		return (NULL);
	img = mlx_xpm_file_to_image(data->mlx, path, &(img_size[0]),
			&(img_size[1]));
	free(path);
	return (img);
}

static char	*set_path(char c)
{
	char	*map_path;

	map_path = NULL;
	if (c == '1')
		map_path = ft_strdup("./texture/sand_wall.xpm");
	if (c == '0')
		map_path = ft_strdup("./texture/sand.xpm");
	if (c == 'C')
		map_path = ft_strdup("./texture/diamond.xpm");
	if (c == 'E')
		map_path = ft_strdup("./texture/char_run1.xpm");
	if (c == 'P')
		map_path = ft_strdup("./texture/portail.xpm");
	return (map_path);
}

static void	put_all_sprit(t_data *data)
{
	data->texture.dragon[0].img = set_texture(set_path('E'), data);
	data->texture.dragon[1].img = set_texture(set_path('E'), data);
	data->texture.portail.img = set_texture(set_path('P'), data);
	data->texture.diamond.img = set_texture(set_path('C'), data);
	if (!data->texture.dragon[0].img || !data->texture.dragon[1].img \
		|| !data->texture.portail.img || !data->texture.diamond.img)
		exit_set_sprite(data);
	set_all_addr(&data->texture);
	put_all_block('E', data->texture.dragon[0].img, data);
	put_all_block('C', data->texture.diamond.img, data);
}
