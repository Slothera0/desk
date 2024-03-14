/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:42:01 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 06:43:10 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

static void	*put_all_block(char c, void *texture, t_data *data);
static char	*set_path(char c);
static void	*set_texture(char *path, t_data *data);
static void	put_all_sprit(t_data *data);

void	print_map(t_data *data)
{
	void	*mlx_win;
	int		x;
	int		y;

	data->total_coin = 0;
	y = ft_arraylen(data->map);
	x = ft_strlen(data->map[y - 1]);
	mlx_win = mlx_new_window(data->mlx, x * BLOCK, y * BLOCK, "so_long");
	data->mlx_win = mlx_win;
	BACK = set_texture(set_path('0'), data);
	put_all_block('0', BACK, data);
	data->texture.wall = set_texture(set_path('1'), data);
	put_all_block('1', data->texture.wall, data);
	put_all_sprit(data);
}

static void	*put_all_block(char c, void *texture, t_data *data)
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
					texture, j * BLOCK, i * BLOCK);
			if (data->map[i][j] == 'C')
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
		error(); // free + message + ratio
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
		map_path = ft_strdup("./texture_2/sand_wall.xpm"); // remettre les bonnes textures
	if (c == '0')
		map_path = ft_strdup("./texture_2/sand.xpm");
	if (c == 'C')
		map_path = ft_strdup("./texture_2/diamond.xpm");
	if (c == 'E')
		map_path = ft_strdup("./texture_2/char_run1.xpm");
	if (c == 'P')
		map_path = ft_strdup("./texture_2/portail.xpm");
	if (c == 'M')
		map_path = ft_strdup("./texture/mouse_run1.xpm");
	return (map_path);
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
	texture->mouse[0].addr = mlx_get_data_addr(texture->mouse[0].img, \
		&texture->mouse[0].bits_per_pixel, &texture->mouse[0].line_length, \
		&texture->mouse[0].endian);
	texture->diamond.addr = mlx_get_data_addr(texture->diamond.img, \
		&texture->diamond.bits_per_pixel, &texture->diamond.line_length, \
		&texture->diamond.endian);
	texture->portail.addr = mlx_get_data_addr(texture->portail.img, \
		&texture->portail.bits_per_pixel, &texture->portail.line_length, \
		&texture->portail.endian);
	//faire tab de mouse et boucler
	texture->dragon[0].id = 1;
	texture->dragon[1].id = 1;
	texture->mouse[0].id = 2;
	texture->portail.id = 3;
	texture->diamond.id = 3;
	pos_temp[0] = 0;
	pos_temp[1] = 0;
	replace_pixel(&(texture->dragon[0]), &(texture->background), pos_temp);
	replace_pixel(&(texture->portail), &(texture->background), pos_temp);
	replace_pixel(&(texture->diamond), &(texture->background), pos_temp);
}

void	replace_pixel(t_image *img, t_image *back, int pos[2])
{
	int	i;
	int	j;

	i = 0;
	while ((i < DRG_H && img->id == 1) || (i < MOUSE_H && img->id == 2) || (i < BLOCK && img->id == 3))
	{
		j = 0;
		while ((j < DRG_W && img->id == 1) || (j < MOUSE_W && img->id == 2) || (j < BLOCK && img->id == 3))
		{
			if (*(unsigned int *)(img->addr \
				+ (i * img->line_length + j * 4)) == GREEN)
			{
				*(unsigned int *)(img->addr + (i * img->line_length + j * 4)) \
					= *(unsigned int *)(back->addr + ((i + pos[1]) % BLOCK \
					* back->line_length + (j + pos[0]) % BLOCK * 4));
			}
			j++;
		}
		i++;
	}
}

static void	put_all_sprit(t_data *data)
{
	data->texture.dragon[0].img = set_texture(set_path('E'), data);
	data->texture.mouse[0].img = set_texture(set_path('M'), data);
	data->texture.portail.img = set_texture(set_path('P'), data);
	data->texture.diamond.img = set_texture(set_path('C'), data);
	set_all_addr(&data->texture);
	put_all_block('E', data->texture.dragon[0].img, data);
	put_all_block('P', data->texture.portail.img, data);
	put_all_block('C', data->texture.diamond.img, data);
}
