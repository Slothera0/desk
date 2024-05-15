/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:33 by arvoyer           #+#    #+#             */
/*   Updated: 2024/03/18 16:48:32 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	int			ret;
	char		*buf;

	str = ft_strdup_stop(buffer, '\n', 1);
	if (buffer)
		suppr_current_line(buffer, &buffer);
	if (str && str[ft_strlen(str) - 1] == '\n')
		return (str);
	ret = 1;
	while (ret > 0)
	{
		ret = read_line(&buf, fd);
		if (ret == 0)
			return (str);
		else if (ret < 0)
			return (NULL);
		str = ft_strjoin_gnl(str, ft_strdup_stop(buf, '\n', 1));
		suppr_current_line(buf, &buffer);
		if (!str || str[ft_strlen(str) - 1] == '\n')
			break ;
	}
	return (str);
}

int	read_line(char **buf, int fd)
{
	int		ret;

	ret = 1;
	(*buf) = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (-1);
	ret = read(fd, (*buf), BUFFER_SIZE);
	if (ret > 0)
		(*buf)[ret] = '\0';
	else
		free((*buf));
	return (ret);
}

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*final_str;

	final_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!final_str)
		return (free(s1), free(s2), NULL);
	final_str[0] = '\0';
	if (s1)
		ft_strlcat(final_str, s1, (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s2)
		ft_strlcat(final_str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	double_free(s1, s2);
	return (final_str);
}
