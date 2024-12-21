/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:56 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/21 20:13:02 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd_1(t_list *node)
{
	pid_t	fork_id;

	if (node->fd_in == -1)
		return (close(node->pipefd1), perror(node->argv[1]), 1);
	fork_id  = fork();
	if (fork_id == 0)
	{
		if (dup2(node->fd_in, STDIN_FILENO) < 0)
			return (close(node->pipefd1), close(node->fd_in), 1);
		close(node->fd_in);
		if (dup2(node->pipefd1, STDOUT_FILENO) < 0)
			return (close(node->pipefd1), 1);
		close(node->pipefd1);
		execve(node->path_cmd1, node->cmd_1_options, node->envp);
	}
	return (0);
}

int	exec_cmd_2(t_list *node)
{
	pid_t	fork_id;
	if (node->fd_out == -1)
		return (close(node->pipefd0), perror(node->argv[5]), 1);
	if (dup2(node->pipefd0, STDIN_FILENO) < 0)
		return (perror(node->cmd_2_options[0]), close(node->fd_out), close(node->pipefd0), 1);
	close(node->pipefd1);
	if (dup2(node->fd_out, STDOUT_FILENO) < 0)
		return (perror(node->cmd_2_options[0]), close(node->fd_out), close(node->pipefd0), 1);
	close(node->fd_out);
	close (node->pipefd0);
	fork_id = fork();
	if (fork_id == -1)
		return (perror("Fork"), 1);
	if (execve(node->path_cmd2, node->cmd_2_options, node->envp) == -1)
		perror(node->cmd_2_options[0]);
	return (0);
}
/*
static int	exec_fork_cmd2(int fd_out, char **cmd2,
								char *path2, char **envp, int pipefd)
{
	int		status;
	pid_t	child;

	child = 2;
	if (path2 && fd_out != -1)
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
}*/
/*
int	exec_cmd(char *path_cmd1, char *path_cmd2, char **cmd1, char **cmd2,
				char **envp, char **argv, int fd_in, int fd_out)
{
	int		status;
	int		pipefd[2];
	pid_t	child;

	child = 2;
	if (pipe(pipefd) == -1)
		return (perror("Pipe"), 1);
	if (path_cmd1 && open(argv[1], O_RDONLY) != -1)
		child = fork();
	if (child == -1)
		return (close(pipefd[0]), close(pipefd[1]), perror("Fork"), 1);
	if (child == 0)
	{
		close(pipefd[0]);
		exec_cmd_1(fd_in, cmd1, path_cmd1, envp, pipefd[1]);
		exit(0);
	}
	else if (path_cmd2 != NULL)
	{
		wait(&status);
		close(pipefd[1]);
		exec_fork_cmd2(fd_out, cmd2, path_cmd2, envp, pipefd[0]);
	}
	return (0);
}*/
