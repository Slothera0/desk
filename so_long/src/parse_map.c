/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:45:27 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/15 10:38:40 by arvoyer          ###   ########.fr       */
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
	char	*map_adress;
	int		nb_line;

	map_adress = ft_strjoin("./maps/", map_name);
	nb_line = count_line_map(map_adress);
	if (nb_line == 0)
	{
		free(map_adress);
		error(NULL);
	}
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
	 	error(NULL);
	if (fill_map(map, map_adress))
	{
		free(map);
		free(map_adress);
		error(NULL);
	}
	free(map_adress);
	return (map);	
}

static int	count_line_map(char *map_adress)
{
	int		fd;
	int		count_line;
	char	*str;

	fd = open(map_adress, O_RDONLY); // suppr cette fonction et remplacer a l'aide d'un tab dynamique
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
