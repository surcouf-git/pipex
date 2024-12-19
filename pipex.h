/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:33:24 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:26 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

char 	*ft_strjoin_bin(char *str, char *join);
int		ft_strlen(char *str);
char	**parse_flags(char **argv, int cmd);
int		exec_cmd_1(int fd_in, char **cmd1, char *path, char **envp, int pipefd);
int		exec_cmd(char *path_cmd1, char *path_cmd2, char **cmd1, char **cmd2, char **envp, int fd_in, int fd_out);
int		exec_cmd_2(int fd_out, char **cmd2, char *path, char **envp, int pipefd);
void	free_all(char **tab);

/*
 * UTILS
 */
char	*check_access(char **path, char *realpath, char *cmd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*real_path(char *cmd, char **envp);
char	**ft_split(const char *s, char c);
int		ft_strncmp(char *argv , char *str, int nb);

#endif
