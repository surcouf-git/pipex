/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:51:18 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/18 22:48:37 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*real_path(char *cmd, char **envp)
{
	char	*realpath;
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i++])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i], ':');
			break ;
		}
	}
	if (!path)
		return (NULL);
	i = 0;
	while (path[i++])
	{
		realpath = ft_strjoin_bin(path[i], cmd);
		if (access(realpath, X_OK | F_OK))
			return (free(realpath), realpath = path[i], free_all(path), realpath);
		free(realpath);
	}
	return (free_all(path), NULL);
}

