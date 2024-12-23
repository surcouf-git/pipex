/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:54:14 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/23 10:25:30 by mvannest         ###   ########.fr       */
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

char	**parse_flags(char **argv, int cmd)
{
	char	**flags;

	flags = ft_split(argv[cmd], ' ');
	if (!flags)
		return (NULL);
	return (flags);
}

void	free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
