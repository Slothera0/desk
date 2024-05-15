/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:42:18 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:37:49 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_pos(char **map, int pos[2]);
static void	clean_map(char **map);
static void	test_map_r(char **map, int i, int j);
static int	verif_map(char **map);

int	test_map(char **map)
{
	int	pos[2];

	set_pos(map, pos);
	if (pos[0] == -1)
		return (1);
	test_map_r(map, pos[1], pos[0]);
	if (verif_map(map))
		return (1);
	clean_map(map);
	return (0);
}

static void	test_map_r(char **map, int i, int j)
{
	if (map[i][j] == '0')
		map[i][j] = 'o';
	else if (map[i][j] == 'C')
		map[i][j] = 'c';
	else if (map[i][j] == 'E')
		map[i][j] = 'e';
	else if (map[i][j] == 'P')
		map[i][j] = 'p';
	else
		error(map);
	if (map[i + 1] && (map[i + 1][j] == '0' || map[i + 1][j] == 'C' \
		|| map[i + 1][j] == 'E' || map[i + 1][j] == 'P'))
		test_map_r(map, i + 1, j);
	if (map[i][j + 1] && (map[i][j + 1] == '0' || map[i][j + 1] == 'C' \
		|| map[i][j + 1] == 'E' || map[i][j + 1] == 'P'))
		test_map_r(map, i, j + 1);
	if (i > 0 && (map[i - 1][j] == '0' || map[i - 1][j] == 'C' \
		|| map[i - 1][j] == 'E' || map[i - 1][j] == 'P'))
		test_map_r(map, i - 1, j);
	if (j > 0 && (map[i][j - 1] == '0' || map[i][j - 1] == 'C' \
		|| map[i][j - 1] == 'E' || map[i][j - 1] == 'P'))
		test_map_r(map, i, j - 1);
}

static int	verif_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((!map[i + 1] || map[i][j + 1] == '\n' || i == 0 || j == 0) \
				&& map[i][j] != '1' && map[i][j] != '\n')
				return (1);
			if (map[i][j] == 'P' || map[i][j] == 'C')
				return (1);
			if (map[i][j] == 'p')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

static void	clean_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'o')
				map[i][j] = '0';
			else if (map[i][j] == 'c')
				map[i][j] = 'C';
			else if (map[i][j] == 'e')
				map[i][j] = 'E';
			else if (map[i][j] == 'p')
				map[i][j] = 'P';
			j++;
		}
		i++;
	}
}

static void	set_pos(char **map, int pos[2])
{
	int	i;
	int	j;

	i = 0;
	pos[0] = -1;
	pos[1] = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' && pos[0] != -1)
			{
				pos[0] = -1;
				return ;
			}
			else if (map[i][j] == 'E')
			{
				pos[0] = j;
				pos[1] = i;
			}
			j++;
		}
		i++;
	}
}
