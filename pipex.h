/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:33:24 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/18 14:56:33 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
#include <fcntl.h>
# include "printf/ft_printf.h"

char *ft_strjoin_bin(char *str, char *join);
int	ft_strlen(char *str);
char	**parse_flags(char **argv, int cmd);
int	*count_flags(char **flags_cmd1,char **flags_cmd2);
void	free_all(char **tab);

/*
 * UTILS
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(const char *s, char c);

#endif
