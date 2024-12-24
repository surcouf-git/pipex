/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:54:14 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/24 18:38:11 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_bin(char *str, char *join)
{
	char	*new_line;
	int		i;
	int		o;

	if (!str || !join)
		return (NULL);
	i = ft_strlen(str);
	o = ft_strlen(join);
	new_line = malloc((i + o + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	o = 0;
	i = 0;
	while (str[i])
		new_line[i++] = str[o++];
	new_line[i++] = '/';
	o = 0;
	while (join[o])
	{
		new_line[i + o] = join[o];
		o++;
	}
	new_line[i + o] = '\0';
	return (new_line);
}

void	free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	close_wait_and_check_status(t_list **node)
{
	close((*node)->pipefd0);
	close((*node)->pipefd1);
	waitpid((*node)->fork_1_id, &(*node)->status_1, 0);
	waitpid((*node)->fork_2_id, &(*node)->status_2, 0);
	close((*node)->fd_in);
	close((*node)->fd_out);
}
