/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:51:18 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/18 17:38:32 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*real_path(char *cmd, char **envp)
{
	char	*realpath;
	char	**path;

	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i][5], ':');
			break ;
		}
		i++;
	}
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		realpath = ft_strjoin_bin(path[i], cmd);
		if (access(realpath, X_OK | F_OK))
			return (free(realpath), realpath = path[i], free_all(path), realpath);
		i++;
	}
	return (free(realpath), free_all(path), NULL);
}
