/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:54:14 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/18 17:39:12 by mvannest         ###   ########.fr       */
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

char *ft_strjoin_bin(char *str, char *join)
{
	if (!str || !join)
		return (NULL);
	char	*new_line;
	int		i;
	int		o;

	i = ft_strlen(str);
	o = ft_strlen(join);
	new_line = malloc((i + o + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	o = 0;
	i = 0;
	while (str[i])
		new_line[i++] = str[o++];
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
	flags = ft_split(argv[cmd]);
	if (!flags)
		return (NULL);
	return (flags);
}

int	*count_flags(char **flags_cmd1,char **flags_cmd2)
{
	int	*count;
	int	i;

	i = 0;
	while(flags_cmd1[i])
		i++;
	count[0] = i;
	i = 0;
	while(flags_cmd2[i])
		i++;
	count[1] = i;
	return (count);
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
