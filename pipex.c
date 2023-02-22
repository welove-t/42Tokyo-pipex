/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 11:10:08 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child_last(t_pipex *pipex, int idx_proc)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(pipex->proc[idx_proc].cmd);
	if (!cmd_line[0])
	{
		error_not_exist_cmd(pipex->proc[idx_proc].cmd);
		exit(1);
	}
	input_pipe_dup_close(pipex->proc[idx_proc - 1].pfd);
	redirect_out_dup_close(pipex);
	do_execve(cmd_line);
}

void	do_child_middle(t_pipex *pipex, int idx_proc)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(pipex->proc[idx_proc].cmd);
	if (!cmd_line[0])
	{
		error_not_exist_cmd(pipex->proc[idx_proc].cmd);
		exit(1);
	}
	input_pipe_dup_close(pipex->proc[idx_proc - 1].pfd);
	output_pipe_dup_close(pipex->proc[idx_proc].pfd);
	do_execve(cmd_line);
}

void	do_child_first(t_pipex *pipex, int idx_proc)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(pipex->proc[idx_proc].cmd);
	if (!cmd_line[0])
	{
		error_not_exist_cmd(pipex->proc[idx_proc].cmd);
		exit(1);
	}
	redirect_in_dup_close(pipex);
	output_pipe_dup_close(pipex->proc[idx_proc].pfd);
	do_execve(cmd_line);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_pipex	pipex;

	initialize(argc, argv, &pipex);
	if (!pipex.min_arg_size || argc < pipex.min_arg_size)
		return (0);
	i = 0;
	while (i < pipex.cnt_proc)
	{
		if (i < pipex.cnt_proc - 1)
			do_pipe(pipex.proc[i].pfd);
		pipex.proc[i].pid = do_fork();
		if (i == 0 && pipex.proc[i].pid == 0)
			do_child_first(&pipex, i);
		else if (i == pipex.cnt_proc - 1 && pipex.proc[i].pid == 0)
			do_child_last(&pipex, i);
		else if (pipex.proc[i].pid == 0)
			do_child_middle(&pipex, i);
		else
			close_pipe(pipex.proc, i);
		i++;
	}
	do_waitpid_pipex(pipex.proc, pipex.cnt_proc);
	return (0);
}

// ./pipex infile "grep a1" "wc -l" outfile
