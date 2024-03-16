/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:23:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/16 18:05:54 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	set_pos(t_data *data);

int	main(int argc, char **argv)
{
	t_data		data;
	//prendre en compte uniquement les .ber et ban les autres lettres de la map
	if (argc > 2)
		return(ft_putstr_fd("Error : wrong number of argument", 2), 2);
	if (argc == 2)
		data.map = parse_map(argv[1]);
	else
		data.map = parse_map("map_01.ber");
	if (test_map(data.map))
		error(data.map);
	data.mlx = mlx_init();
	if (!data.mlx)
		error(data.map);
	print_map(&data);
	if (!data.mlx_win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		error(data.map);
	}
	init_mouse(&data); // faire un exit en cas de prob
	set_pos(&data);
	start_game(&data);
	ft_free_array(data.map);
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
