/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:22:00 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/26 19:42:02 by mbaron-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_access(char *str, char *cmd);

char	*find_path(char **path, char *cmd)
{
	char	*cmd_path;
	int		i;

	cmd_path = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == -1)
			return (NULL);
		cmd_path = ft_strdup(cmd);
		return (cmd_path);
	}
	i = 0;
	while (path && path[i] && ft_strncmp(path[i], "PATH=", 5))
		i++;
	if (path && path[i])
		cmd_path = search_access(path[i], cmd);
	return (cmd_path);
}

static char	*search_access(char *str, char *cmd)
{
	char	*path;
	int		i;
	int		len;

	i = 5;
	while (str[i])
	{
		len = ft_strlen_c(&(str[i]), ':') + ft_strlen(cmd) + 2;
		path = malloc(sizeof(char) * len);
		if (!path)
			return (NULL);
		*path = '\0';
		ft_strlcpy(path, &(str[i]), ft_strlen_c(&(str[i]), ':') + 1);
		ft_strlcat(path, "/", len);
		ft_strlcat(path, cmd, len);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		while (str[i] && str[i] != ':')
			i++;
		i++;
	}
	return (NULL);
}
