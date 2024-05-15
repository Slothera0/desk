/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:45:27 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 14:42:54 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"

static int	fill_map(char **map, char *map_adress);
static int	count_line_map(char *map_adress);

char	**parse_map(char *map_name)
{
	char	**map;
	int		nb_line;
	int		i;

	i = ft_strlen(map_name) - 4;
	if (i < 0)
		error(NULL);
	if (ft_strncmp(&(map_name[i]), ".ber", 4) != 0)
		error(NULL);
	nb_line = count_line_map(map_name);
	if (nb_line == 0)
		error(NULL);
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		error(NULL);
	if (fill_map(map, map_name))
	{
		free(map);
		error(NULL);
	}
	return (map);
}

static int	count_line_map(char *map_adress)
{
	int		fd;
	int		count_line;
	char	*str;

	fd = open(map_adress, O_RDONLY);
	if (fd == -1)
		return (0);
	count_line = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		count_line++;
		str = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

static int	fill_map(char **map, char *map_adress)
{
	int		fd;
	int		i;

	fd = open(map_adress, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (0);
}
