/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:51:18 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/23 16:36:49 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(char **path, char *cmd)
{
	int		i;
	char	*realpath;

	i = 1;
	realpath = NULL;
	while (path[i++])
	{
		realpath = ft_strjoin_bin(path[i], cmd);
		if (realpath && access(realpath, X_OK | F_OK) == 0)
			return (realpath);
		free(realpath);
		realpath = NULL;
	}
	ft_putstr(cmd);
	ft_putstr(":command not found\n");
	return (NULL);
}

char	*real_path(char *cmd, char **envp)
{
	char	*realpath;
	char	**path;
	int		i;

	i = 0;
	realpath = NULL;
	path = NULL;
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK | F_OK) == 0)
		return (cmd);
	while (envp[i++])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
	if (!path)
		return (NULL);
	realpath = check_access(path, cmd);
	return (free_all(path), realpath);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
