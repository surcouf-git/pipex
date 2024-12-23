/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:56 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/23 15:09:41 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd_1(t_list **node)
{
	pid_t	fork_id;
	int		status;

	fork_id = fork();
	if (fork_id == 0)
	{
		close((*node)->pipefd0);
		dup2((*node)->fd_in, STDIN_FILENO);
		dup2((*node)->pipefd1, STDOUT_FILENO);
		close((*node)->fd_in);
		close((*node)->pipefd1);
		fprintf(stderr, "%p : %s, %s, %s--- exec\n", (*node)->path_cmd1, (*node)->path_cmd1, (*node)->cmd_1_opt[0], (*node)->cmd_1_opt[1]);
		execve((*node)->path_cmd1, (*node)->cmd_1_opt, (*node)->envp);
		perror((*node)->cmd_1_opt[0]);
		exit(EXIT_FAILURE);
	}
	else if (fork_id > 0)
		waitpid(fork_id, &status, 0);
	else
		perror("Fork");
	printf("%p, %s, execfinish\n", (*node)->path_cmd1, (*node)->path_cmd1);
	return (0);
}

int	exec_cmd_2(t_list **node)
{
	pid_t	fork_id;
//	int		status;

	fork_id = fork();
	if (fork_id == 0)
	{
		close((*node)->pipefd1);
		dup2((*node)->pipefd0, STDIN_FILENO);
		dup2((*node)->fd_out, STDOUT_FILENO);
		close((*node)->pipefd0);
		close((*node)->fd_out);
		execve((*node)->path_cmd2, (*node)->cmd_2_opt, (*node)->envp);
		perror((*node)->cmd_2_opt[0]);
		exit(EXIT_FAILURE);
	}
	/*else if (fork_id > 0)
		wait(&status);*/
	else if (fork_id < 0)
		perror("Fork");
	return (0);
}
