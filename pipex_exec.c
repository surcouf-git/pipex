/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:56 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/20 18:47:45 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exec_cmd_1(int fd_in, char **cmd1, char *path, char **envp, int pipefd)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		return (close(pipefd), close(fd_in), 1);
	close(fd_in);
	if (dup2(pipefd, STDOUT_FILENO) < 0)
		return (close(pipefd), 1);
	close(pipefd);
	if (execve(path, cmd1, envp) == -1)
		return (perror(cmd1[0]), 1);
	return (0);
}

static int	exec_cmd_2(int fd_out, char **cmd2, char *path, char **envp, int pipefd)
{
	if (dup2(pipefd, STDIN_FILENO) < 0)
		return (perror(cmd2[0]), close(fd_out), close(pipefd), 1);
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		return (perror(cmd2[0]), close(fd_out), close(pipefd), 1);
	close(fd_out);
	close (pipefd);
	if (execve(path, cmd2, envp) == -1)
		perror(cmd2[0]);
	return (0);
}

static int	exec_fork_cmd2(int fd_out, char **cmd2, char *path2, char **envp, int pipefd)
{
	int		status;
	pid_t	child;

	child = fork();
	if (child == -1)
		return (close(pipefd), perror("Fork"), 1);
	if (child == 0)
	{
		exec_cmd_2(fd_out, cmd2, path2, envp, pipefd);
		exit(0);
	}
	else
		wait (&status);
	return (0);
}

int	exec_cmd(char *path_cmd1, char *path_cmd2, char **cmd1, char **cmd2, char **envp, int fd_in, int fd_out)
{
	int		status;
	int		pipefd[2];
	pid_t	child;

	if (pipe(pipefd) == -1)
		return (perror("Pipe"), 1);
	child = fork();
	if (child == -1)
		return (close(pipefd[0]), close(pipefd[1]), perror("Fork"), 1);
	if (child == 0)
	{
		close(pipefd[0]);
		exec_cmd_1(fd_in, cmd1, path_cmd1, envp, pipefd[1]);
		exit(0);
	}
	else
	{
		wait(&status);
		close(pipefd[1]);
		exec_fork_cmd2(fd_out, cmd2, path_cmd2, envp, pipefd[0]);
	}
	return (0);
}
