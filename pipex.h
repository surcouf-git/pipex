/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:33:24 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/24 17:26:01 by mvannest         ###   ########.fr       */
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
	int		status_1;
	int		status_2;
	pid_t	fork_1_id;
	pid_t	fork_2_id;
}	t_list;

/*********** exec fonctions ***********/
char	*ft_strdup(char *str);
int		exec_cmd_1(t_list **node);
int		exec_cmd_2(t_list **node);
/*********** exec utils ***********/
char	*real_path(char *cmd, char **envp);
char	*check_access(char **path, char *cmd);
char	*ft_strjoin_bin(char *str, char *join);
void	close_wait_and_check_status(t_list **node);
/*********** struct utils ***********/
void	free_all(char **tab);
void	free_struct(t_list **node);
void	calloc_struct(t_list **node);
char	**ft_split(const char *s, char c);
/*********** global utils ***********/
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strncmp(char *argv, char *str, int nb);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
