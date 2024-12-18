/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:33:24 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/18 22:56:57 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
#include <fcntl.h>

char 	*ft_strjoin_bin(char *str, char *join);
int		ft_strlen(char *str);
char	**parse_flags(char **argv, int cmd);
int		*count_flags(char **flags_cmd1,char **flags_cmd2);
void	free_all(char **tab);

/*
 * UTILS
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*real_path(char *cmd, char **envp);
char	**ft_split(const char *s, char c);
int		ft_strncmp(char *argv , char *str, int nb);

#endif
