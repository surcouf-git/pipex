/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:48 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/18 15:34:55 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd_1(int fd, char **cmd2, char **envp, int pipefd)
{
	char	*realpath;
	(void)fd;

	dup2(pipefd, STDOUT_FILENO);
	close(pipefd);
	realpath = ft_strjoin_bin("/bin/", cmd1[0]);
	if (execve((const char *)realpath, cmd1, envp) == -1)
		return (free(realpath), perror("Execve CMD 1 :"), 1);
	return (free(realpath), 0);
}

int	exec_cmd_2(int fd_out, char **cmd1, char **envp, int pipefd)
{
	char	*realpath;

	dup2(fd_out, STDOUT_FILENO);
	close(pipefd);
	realpath = ft_strjoin_bin("/bin/", cmd2[0]);
	if (execve((const char *)realpath, cmd2, envp) == -1)
		return (free(realpath), perror("Execve CMD 2 :"), 1);
	return (free(realpath), 0);
}

int	exec_cmd(char **cmd1, char **cmd2, char **envp, int fd_in, int fd_out)
{
	char	*realpath;
	int		pipefd[2];
	__pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe :"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("Fork :"), 1);
	if (pid == 0)
	{
		close(pipe[0]);
		exec_cmd_1(fd_in, cmd1, envp, pipefd[1]);
	}
	else
	{
		wait(NULL);
		close(pipe[1]);
		exec_cmd_2(fd_out, cmd2, envp, pipefd[0]);
	}
	return (0);
}

int	pipex(char **argv, char **envp, int fd_in, int fd_out)
{
	int		*count;
	char	**flags_cmd1;
	char	**flags_cmd2;

	flags_cmd1 = NULL;
	flags_cmd2 = NULL;
	flags_cmd1 = parse_flags(argv, 2);
	flags_cmd2 = parse_flags(argv, 3);
	count = count_flags(flags_cmd1, flags_cmd2);
	exec_cmd(flags_cmd1, flags_cmd2, envp, fd_in, fd_out);
	return (free_all(flags_cmd1), free_all(flags_cmd2), 0);
}

int main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (argc != 5)
		return (EXIT_FAILURE);
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_in == -1)
		return (perror(argv[1]));
	pipex(argv, fd_in, fd_out, envp);
	return (EXIT_SUCCESS);
}
