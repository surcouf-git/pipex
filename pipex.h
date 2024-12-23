/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:33:24 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/23 16:37:17 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_list
{
	char	**argv;
	char	**envp;
	char	**cmd_1_opt;
	char	**cmd_2_opt;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*outfile;
	char	*infile;
	int		exec_cmd1;
	int		exec_cmd2;
	int		fd_in;
	int		fd_out;
	int		pipefd0;
	int		pipefd1;
}	t_list;

char	**parse_flags(char **argv, int cmd);
char	*ft_strjoin_bin(char *str, char *join);
int		ft_strlen(char *str);
void	free_all(char **tab);
int		exec_cmd_1(t_list *node);
int		exec_cmd_2(t_list *node);
char	*ft_strdup(char *str);
/*
 * UTILS
 */
char	*check_access(char **path, char *cmd);
char	*real_path(char *cmd, char **envp);
char	**ft_split(const char *s, char c);
int		ft_strncmp(char *argv, char *str, int nb);
int		ft_putstr(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
