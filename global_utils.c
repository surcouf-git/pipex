/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:23 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/22 13:08:42 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *argv, char *str, int nb)
{
	int	i;

	i = 0;
	while (argv[i] && i < nb)
	{
		if (argv[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}
