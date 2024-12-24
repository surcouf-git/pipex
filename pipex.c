/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:48 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/24 19:00:11 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd_1(t_list **node)
{
	(*node)->fork_1_id = fork();
	if ((*node)->fork_1_id == 0)
	{
		close((*node)->pipefd0);
		dup2((*node)->fd_in, STDIN_FILENO);
		dup2((*node)->pipefd1, STDOUT_FILENO);
		close((*node)->fd_in);
		close((*node)->pipefd1);
		execve((*node)->path_cmd1, (*node)->cmd_1_opt, (*node)->envp);
		perror((*node)->cmd_1_opt[0]);
		exit(126);
	}
	else if ((*node)->fork_1_id < 0)
		return (perror("Fork command 1"), 1);
	return (0);
}

int	exec_cmd_2(t_list **node)
{
	(*node)->fork_2_id = fork();
	if ((*node)->fork_2_id == 0)
	{
		close((*node)->pipefd1);
		dup2((*node)->pipefd0, STDIN_FILENO);
		dup2((*node)->fd_out, STDOUT_FILENO);
		close((*node)->pipefd0);
		close((*node)->fd_out);
		execve((*node)->path_cmd2, (*node)->cmd_2_opt, (*node)->envp);
		perror((*node)->cmd_2_opt[0]);
		exit(126);
	}
	else if ((*node)->fork_2_id < 0)
		return (perror("Fork command 2"), 1);
	return (0);
}

static int	exec_all(t_list **node)
{
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (perror("Pipe"), 1);
	(*node)->pipefd0 = pipefd[0];
	(*node)->pipefd1 = pipefd[1];
	if ((*node)->path_cmd1 != NULL && (*node)->fd_in != -1)
		exec_cmd_1(node);
	if ((*node)->path_cmd2 != NULL && (*node)->fd_out != -1)
		exec_cmd_2(node);
	close_wait_and_check_status(node);
	free_struct(node);
	return (0);
}

t_list	*init_struct(char **argv, char **envp)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	calloc_struct(&node);
	node->argv = argv;
	node->envp = envp;
	node->cmd_1_opt = ft_split(argv[2], ' ');
	node->cmd_2_opt = ft_split(argv[3], ' ');
	node->fd_in = open(node->argv[1], O_RDONLY);
	if (node->fd_in == -1)
		perror(node->argv[1]);
	else
		node->path_cmd1 = real_path(ft_strdup(node->cmd_1_opt[0]), envp);
	node->fd_out = open(node->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (node->fd_out == -1)
		perror(node->argv[4]);
	else
		node->path_cmd2 = real_path(ft_strdup(node->cmd_2_opt[0]), envp);
	node->infile = node->argv[1];
	node->outfile = node->argv[4];
	return (node);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*node;

	if (argc != 5)
		return (ft_putstr("Usage : infile cmd1 cmd2 outfile\n"), 1);
	node = init_struct(argv, envp);
	if (!node)
		return (ft_putstr("some memory allocation failed\n"), 1);
	exec_all(&node);
}
