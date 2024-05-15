/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:23:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:40:39 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

static void	set_pos(t_data *data);

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (ft_putendl_fd("Error : wrong number of argument", 2), 2);
	if (argc == 2)
		data.map = parse_map(argv[1]);
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
	set_pos(&data);
	start_game(&data);
	ft_free_array(data.map);
	return (0);
}

static void	set_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->pos[0] = j * BLC;
				data->pos[1] = i * BLC;
			}
			j++;
		}
		i++;
	}
}
