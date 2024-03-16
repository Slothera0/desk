/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:24:19 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/16 18:31:23 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

# define BLOCK 128
# define WALK 16
# define FLY 64
# define GREEN 2030152
# define DRG_H 68
# define DRG_W 124
# define MOUSE_H 32
# define MOUSE_W 18
# define LEFT 2
# define RIGHT 1
# define TEXT_USE (data->player_move + (data->natural_move) / 30) % 2
# define BACK data->texture.background.img
# define POS_X data->pos[0]
# define POS_Y data->pos[1]
# define MOUSE data->mouse
# define MWALK 4
# define MPOS_X mouse->pos[0]
# define MPOS_Y mouse->pos[1]

typedef struct	s_image 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		id;
}	t_image;

typedef struct s_mouse
{
	t_image	mouse[2];
	int		look;
	char	move_side[2];
	int		pos[2];
}	t_mouse;


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
	t_mouse		*mouse;
	int			player_move;
	int			natural_move;
	int			total_coin;
	int			pos[2];
	int			drg_look;
	char		drg_move_side[2];
	int			mouse_nbr;
	int			do_movement;
	int			bool_portail;
}	t_data;

char	**parse_map(char *map_name);
void	print_map(t_data *data);
int		start_game(t_data *data);
int		move_dragon(t_data *data, int side);
int		fly_char(t_data *data);
int		do_gravity(t_data *data);
int		move_mouse(t_data *data, int i); // passer en static
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
void	init_mouse(t_data *data);
void	mouse_error();
int		mouse_movement(t_data *data);

#endif