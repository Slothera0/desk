/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:29:41 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/16 15:05:20 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	exit_during_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->texture.background.img);
	if (TEXT_USE == 0)
		mlx_destroy_image(data->mlx, data->texture.dragon[1].img);
	else
		mlx_destroy_image(data->mlx, data->texture.dragon[0].img);
	mlx_destroy_image(data->mlx, data->texture.wall);
	mlx_destroy_image(data->mlx, data->texture.portail.img);
	mlx_destroy_image(data->mlx, data->texture.diamond.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	exit_set_sprite(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->texture.dragon[0].img)
		mlx_destroy_image(data->mlx, data->texture.dragon[0].img);
	if (data->texture.dragon[1].img)
		mlx_destroy_image(data->mlx, data->texture.dragon[1].img);
	if (data->texture.portail.img)
		mlx_destroy_image(data->mlx, data->texture.portail.img);
	if (data->texture.diamond.img)
		mlx_destroy_image(data->mlx, data->texture.diamond.img);
	mlx_destroy_image(data->mlx, BACK);
	mlx_destroy_image(data->mlx, data->texture.wall);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	error(char **map)
{
	ft_free_array(map);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	mouse_error()
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}