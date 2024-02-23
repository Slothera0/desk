/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:38:26 by arvoyer           #+#    #+#             */
/*   Updated: 2024/02/23 16:47:30 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	if (access(cmd, X_OK) == 0)
	{
		path = ft_strdup(cmd);
		return (path);
	}
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	if (envp[i])
		path = search_access(envp[i], cmd);
	else
		path = search_access(CONST_PATH, cmd);
	return (path);
}

char	*search_access(char *str, char *cmd)
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
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		while (str[i] && str[i] != ':')
			i++;
		i++;
	}
	return (NULL);
}
