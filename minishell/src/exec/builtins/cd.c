/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:22:32 by arvoyer           #+#    #+#             */
/*   Updated: 2024/04/25 15:44:47 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static char	*get_home_dir(char **env);
static int	change_pwd(char ***env);
static int	set_old_pwd(char **env, char *old_pwd);
static int	set_new_pwd(char **pwd);

int	cd(char ***env, char *path)
{
	if (!path && env)
		path = get_home_dir(*env);
	if (!path)
	{
		if (errno == 0)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (1);
		}
		return (error("minishell: cd"));
	}
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		error(path);
	}
	if (env && change_pwd(env))
		return (error("minishell: cd"));
	return (0);
}

static char	*get_home_dir(char **env)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			path = ft_strdup(&(env[i][5]));
			return (path);
		}
		i++;
	}
	return (NULL);
}

static int	change_pwd(char ***env)
{
	int		i;
	char	*old_pwd;

	i = 0;
	old_pwd = NULL;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], "PWD=", 4) == 0)
		{
			old_pwd = ft_strdup(&((*env)[i][4]));
			if (!old_pwd || set_new_pwd(&((*env)[i])))
				return (1);
		}
		i++;
	}
	if (!old_pwd)
		return (0);
	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], "OLDPWD=", 7) == 0)
			return (set_old_pwd(&(*env)[i], old_pwd));
		i++;
	}
	return (0);
}

static int	set_old_pwd(char **env, char *old_pwd)
{
	char	*temp;

	temp = ft_strjoin("OLDPWD=", old_pwd);
	if (!temp)
		return (1);
	free(*env);
	*env = temp;
	return (0);
}

static int	set_new_pwd(char **pwd)
{
	char	*buf;
	char	*temp;

	buf = getcwd(NULL, 0);
	if (!buf)
		return (1);
	temp = ft_strjoin("PWD=", buf);
	free(buf);
	if (!(*pwd))
		return (1);
	free(*pwd);
	*pwd = temp;
	return (0);
}
