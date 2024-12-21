/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:48 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/21 20:14:42 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*static int	execute(int	pipefd, char **argv, char **envp, char **cmd_options)
{
	static	int command_nb;
	char	*cmd_path;
	int		fd;

	command_nb = 2;
	cmd_path = real_path(argv[command_nb], envp);
	if (!cmd_path)
		return (command_nb++, 1);
	if (command_nb == 2)
		exec_cmd_1(node);
	else
		exec_cmd_2(node);
	command_nb++;
	return (free(cmd_path), 0);
}
int	init_cmd(char **argv, char **envp, int *pipe, int cmd)
{
	char	**cmd_options;
	pid_t	fork_id;
	(void)pipe;
	(void)envp;

	cmd_options = NULL;
	cmd_options = parse_flags(argv, cmd);
	fork_id = fork();
	if (fork_id == 0)
	{
//		exec_cmd(void);
		exit(0);
	}

}*/
void	calloc_struct(t_list **node)
{
	(*node)->argv = NULL;
	(*node)->envp = NULL;
	(*node)->cmd_1_options = NULL;
	(*node)->cmd_2_options = NULL;
	(*node)->path_cmd1 = NULL;
	(*node)->path_cmd2 = NULL;
	(*node)->infile = NULL;
	(*node)->outfile = NULL;
	(*node)->exec_cmd1 = 0;
	(*node)->exec_cmd2 = 0;
	(*node)->fd_in = 0;
	(*node)->fd_out = 0;
	(*node)->pipefd0;
	(*node)->pipefd1;
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
	node->cmd_1_options = ft_split(argv[2], ' ');
	node->cmd_2_options = ft_split(argv[3], ' ');
	node->path_cmd1 = real_path(node->cmd_1_options[0], envp);
	node->path_cmd2 = real_path(node->cmd_2_options[0], envp);
	node->infile = node->argv[1];
	node->outfile = node->argv[5];
	node->fd_in = open(node->argv[1], O_RDONLY);
	node->fd_out = open(node->argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (node);
}

static int	exec_all(t_list *node)
{
	int		pipefd[2];
	pid_t	fork_id;

	if (pipe(pipefd) < 0)
		return (perror("Pipe"), 1);
	node->pipefd0 = pipefd[0];
	node->pipefd1 = pipefd[1];
	if (node->path_cmd1 != NULL)
		exec_cmd_1(node);
	if (node->path_cmd2 != NULL);
		exec_cmd_2(node);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*node;

	node = init_struct(argv, envp);
	if (!node)
		return (putstr("memory allocation failed\n"), 1);
	exec_all(node);
	close (node->fd_in);
	close (node->fd_out);
}
