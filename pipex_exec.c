/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:56 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/19 18:44:48 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd_1(int fd_in, char **cmd1, char *path, char **envp, int pipefd)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
	{
		close(fd_in);
		free_all(cmd1);
		free(path);
		return (perror("dup2 infile"), 1);
	}
	close(fd_in);
	if (dup2(pipefd, STDOUT_FILENO) < 0)
	{
		close(pipefd);
		free_all(cmd1);
		free(path);
		return (perror("dup2 stdout"), 1);
	}
	close(pipefd);
	if (execve(path, cmd1, envp) == -1)
		return (free_all(cmd1), free(path), perror(cmd1[0]), 1);
	return (free_all(cmd1), free(path), 0);
}

int	exec_cmd_2(int fd_out, char **cmd2, char *path, char **envp, int pipefd)
{

	if (dup2(pipefd, STDIN_FILENO) < 0)
	{
		perror("dup2 pipe read");
		return (close(fd_out), close(pipefd), 1);
	}
	if (dup2(fd_out, pipefd) < 0)
	{
		perror("dup2 fdout");
		return (close(fd_out), close(pipefd), 1);
	}
	close(pipefd);
	if (execve(path, cmd2, envp) == -1)
		return (free(path), perror(cmd2[0]), 1);
	return (free(path), 0);
}

int	exec_cmd(char *path_cmd1, char *path_cmd2, char **cmd1, char **cmd2, char **envp, int fd_in, int fd_out)
{
	int		status;
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("Pipe"), 1);
	pid = fork();
	if (pid == -1)
		return (close(pipefd[0]), close(pipefd[1]), perror("Fork"), 1);
	if (pid == 0)
	{
		close(pipefd[0]);
		exec_cmd_1(fd_in, cmd1, path_cmd1, envp, pipefd[1]);
	}
	else
	{
		wait(&status);
		close(pipefd[1]);
		exec_cmd_2(fd_out, cmd2, path_cmd2, envp, pipefd[0]);
	}
	return (0);
}
