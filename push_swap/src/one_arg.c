/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:04:04 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/09 08:36:10 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_p(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_split(char *s)
{
	int		i;
	char	**tab;
	int		j;

	tab = malloc(sizeof(char *) * (1 + tablen(s)));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j] && i < tablen(s))
	{
		if (s[j] == ' ')
			j++;
		if ((s[j] >= '0' && s[j] <= '9') || s[j] == '-')
			tab[i] = ft_strdup_stop(&s[j]);
		if (!tab[i])
			return (free_array(tab, i));
		while ((s[j] >= '0' && s[j] <= '9') || s[j] == '-')
			j++;
		if (s[j] && s[j] != ' ')
			return (free_array(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	*ft_strdup_stop(char *s)
{
	size_t	i;
	size_t	len;
	char	*copy;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != ' ')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	tablen(const char *str)
{
	int	i;
	int	len;
	int	boolean;

	i = 0;
	len = 0;
	boolean = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			boolean = 1;
		if (str[i] == ' ' && i > 0 && str[i - 1] != ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i])
				len++;
		}
		i++;
	}
	return (len + boolean);
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '-') && (s[i] < '0' || s[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
