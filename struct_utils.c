/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:56 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/24 16:53:02 by mvannest         ###   ########.fr       */
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
	(*node)->fork_1_id = 0;
	(*node)->fork_2_id = 0;
	(*node)->status_1 = 0;
	(*node)->status_2 = 0;
}
