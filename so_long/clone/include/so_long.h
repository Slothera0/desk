/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:24:19 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:47:20 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

# define BLC 128
# define WALK 16
# define FLY 64
# define GREEN 2030152
# define DRG_H 68
# define DRG_W 124
# define LEFT 2
# define RIGHT 1

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		id;
}	t_image;

typedef struct s_texture
{
	t_image	background;
	void	*wall;
	t_image	diamond;
	t_image	dragon[2];
	t_image	portail;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_texture	texture;
	int			pmv;
	int			nmv;
	int			total_coin;
	int			pos[2];
	int			drg_look;
	char		drg_move_side[2];
	int			do_movement;
	int			bool_portail;
}	t_data;

char	**parse_map(char *map_name);
void	print_map(t_data *data);
int		start_game(t_data *data);
int		move_dragon(t_data *data, int side);
int		fly_char(t_data *data);
int		do_gravity(t_data *data);
void	error(char **map);
void	replace_pixel(t_image *img, t_image *back, int pos[2]);
void	change_sprit_drg_left(t_data *data);
void	change_sprit_drg_right(t_data *data);
void	change_sprit_drg_fly(t_data *data);
void	clear_pos(t_data *data);
void	apply_texture_drg(t_data *data);
void	change_sprit_drg_gravity(t_data *data);
void	claim_coin(t_data *data);
void	*put_all_block(char c, void *texture, t_data *data);
void	take_portail(t_data *data);
int		test_map(char **map);
void	exit_during_game(t_data *data);
void	exit_set_sprite(t_data *data);
void	set_all_addr(t_texture *texture);
int		print_move(t_data *data);

#endif