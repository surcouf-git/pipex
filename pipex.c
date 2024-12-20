/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:31:48 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/20 13:04:11 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex(char **argv, char **envp, int fd_in, int fd_out)
{
	char	**flags_cmd1;
	char	**flags_cmd2;
	char	*path_cmd1;
	char	*path_cmd2;

	flags_cmd1 = NULL;
	flags_cmd2 = NULL;
	flags_cmd1 = parse_flags(argv, 2);
	flags_cmd2 = parse_flags(argv, 3);
	path_cmd2 = real_path(flags_cmd2[0], envp);
	path_cmd1 = real_path(flags_cmd1[0], envp);
	exec_cmd(path_cmd1, path_cmd2, flags_cmd1, flags_cmd2, envp, fd_in, fd_out);
	return (free(path_cmd1), free(path_cmd2), free_all(flags_cmd1), free_all(flags_cmd2), 0);
}

int main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	(void)argc;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		(perror(argv[1]));
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex(argv, envp, fd_in, fd_out);
	close (fd_in);
	close (fd_out);
	return (EXIT_SUCCESS);
}
