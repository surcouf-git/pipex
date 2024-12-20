/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:51:18 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/20 12:45:46 by mvannest         ###   ########.fr       */
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
		if (access(realpath, X_OK | F_OK) == 0)
			return (realpath);
		free(realpath);
	}
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

