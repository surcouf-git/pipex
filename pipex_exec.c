/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:56 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/21 20:43:28 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd_1(t_list *node)
{
	pid_t	fork_id;
//	int		status;

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
//	else
//		wait(&status);
	return (0);
}

int	exec_cmd_2(t_list *node)
{
	pid_t	fork_id;
	int		status;

	if (node->fd_out == -1)
		return (close(node->pipefd0), perror(node->argv[5]), 1);
	fork_id = fork();
	if (fork_id == -1)
		return (perror("Fork"), 1);
	if (fork_id == 0)
	{
		if (dup2(node->pipefd0, STDIN_FILENO) < 0)
			return (perror(node->cmd_2_options[0]), close(node->fd_out), close(node->pipefd0), 1);
		close(node->pipefd1);
		if (dup2(node->fd_out, STDOUT_FILENO) < 0)
			return (perror(node->cmd_2_options[0]), close(node->fd_out), close(node->pipefd0), 1);
		close(node->fd_out);
		close (node->pipefd0);
		if (execve(node->path_cmd2, node->cmd_2_options, node->envp) == -1)
			perror(node->cmd_2_options[0]);
	}
	else
		wait(&status);
	return (0);
}

