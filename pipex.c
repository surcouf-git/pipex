/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:48 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/23 18:33:29 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_list **node)
{
	if ((*node)->cmd_1_opt != NULL)
		free_all((*node)->cmd_1_opt);
	if ((*node)->cmd_2_opt != NULL)
		free_all((*node)->cmd_2_opt);
	if ((*node)->path_cmd1 != NULL)
		free((*node)->path_cmd1);
	if ((*node)->path_cmd2 != NULL)
		free((*node)->path_cmd2);
	free(*node);
}

void	calloc_struct(t_list **node)
{
	(*node)->argv = NULL;
	(*node)->envp = NULL;
	(*node)->cmd_1_opt = NULL;
	(*node)->cmd_2_opt = NULL;
	(*node)->path_cmd1 = NULL;
	(*node)->path_cmd2 = NULL;
	(*node)->infile = NULL;
	(*node)->outfile = NULL;
	(*node)->exec_cmd1 = 0;
	(*node)->exec_cmd2 = 0;
	(*node)->fd_in = 0;
	(*node)->fd_out = 0;
	(*node)->pipefd0 = 0;
	(*node)->pipefd1 = 0;
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

static int	exec_all(t_list **node)
{
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (perror("Pipe"), 1);
	(*node)->pipefd0 = pipefd[0];
	(*node)->pipefd1 = pipefd[1];
	if ((*node)->path_cmd1 != NULL && (*node)->fd_in != -1)
		exec_cmd_1(*node);
	if ((*node)->path_cmd2 != NULL && (*node)->fd_out != -1)
		exec_cmd_2(*node);
	free_struct(node);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	t_list	*node;

	node = init_struct(argv, envp);
	if (!node)
		return (ft_putstr("some memory allocation failed\n"), 1);
	exec_all(&node);
}
