/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:23:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/14 06:52:21 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

void	set_pos(t_data *data);

int	main(int argc, char **argv)
{
	t_data		data;
	
	if (argc > 2)
		return(ft_putstr_fd("Error : wrong number of argument", 2), 2);
	if (argc == 2)
		data.map = parse_map(argv[1]);
	else
		data.map = parse_map("map_01.ber");
	data.mlx = mlx_init();
	if (!data.mlx)
		error(); // free + message + ratio
	print_map(&data);
	if (!data.mlx_win)
		error(); // free + message + ratio
	set_pos(&data);
	if (start_game(&data) == 1)
		error(); // free + message + ratio
	//free_array(map);
	return (0);
}

void	set_pos(t_data *data)
{
	int	i;
	int	j;
	
	data->mouse_nbr = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			// if (data->map[i][j] == 'M')
			// {
			// 	data->mouse_POS_Y[data->mouse_nbr] = j * BLOCK;
			// 	data->mouse_pos_y[data->mouse_nbr] = i * BLOCK;
			// 	data->mouse_nbr++;	
			// }
			if (data->map[i][j] == 'E')
			{
				POS_X = j * BLOCK;
				POS_Y = i * BLOCK;
			}
			j++;
		}
		i++;
	}
}

void	error()
{
	ft_putstr_fd("Error\n", 2);
}

	// void	*mlx;
	// void	*mlx_win;
	// void	*wall;
	// void	*background;
	// void	*sprit;
	// char	*relative_path = "./texture/wall.xpm";
	// char	*relative_path2 = "./texture/background.xpm";
	// char	*relative_path3 = "./texture/char_run1.xpm";
	// int		img_width;
	// int		img_height;
	// int		x;
	// int		y;

	// x= 0;
	// y = 0;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 704, 704, "Hello world!");
	// wall = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// background = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	// sprit = mlx_xpm_file_to_image(mlx, relative_path3, &img_width, &img_height);
	// while (1)
	// {
	// 	if (x == 0 || x == 640 || y == 0 || y == 640)
	// 		mlx_put_image_to_window(mlx, mlx_win, wall, x, y);
	// 	else
	// 		mlx_put_image_to_window(mlx, mlx_win, background, x, y);
	// 	x += 64;
	// 	if (x > 640)
	// 	{
	// 		x = 0;
	// 		y += 64;
	// 		if (y > 640)
	// 			break;
	// 	}
	// }
	// mlx_put_image_to_window(mlx, mlx_win, sprit, 300, 600);
	// mlx_loop(mlx);
