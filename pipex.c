/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 19:38:20 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child_last(int i_fd[], const char *outfile, char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
	{
		error_not_exist_cmd(cmd);
		exit(1);
	}
	input_pipe_dup_close(i_fd);
	redirect_out_dup_close(outfile);
	do_execve(cmd_line);
}

void	do_child_middle(int i_fd[], int o_fd[], char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
	{
		error_not_exist_cmd(cmd);
		exit(1);
	}
	input_pipe_dup_close(i_fd);
	output_pipe_dup_close(o_fd);
	do_execve(cmd_line);
}

void	do_child_first(int o_fd[], const char *infile, char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
	{
		error_not_exist_cmd(cmd);
		exit(1);
	}
	redirect_in_dup_close(infile);
	output_pipe_dup_close(o_fd);
	do_execve(cmd_line);
}

void	close_pipe(t_proc *proc, int i)
{
	do_close(proc[i].pfd[0]);
	do_close(proc[i].pfd[1]);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_pipex	pipex;


	initialize(argc, argv, &pipex);
	if (!pipex.min_arg_size || argc < pipex.min_arg_size)
		return (0);
	i = 0;
	while (i < argc - 3)
	{
		if (i < argc - 4)
			do_pipe(pipex.proc[i].pfd);
		pipex.proc[i].pid = do_fork();
		if (i == 0 && pipex.proc[i].pid == 0)
			do_child_first(pipex.proc[i].pfd, argv[1], pipex.proc[i].cmd);
		else if (i == argc - 4 && pipex.proc[i].pid == 0)
			do_child_last(pipex.proc[i - 1].pfd, argv[argc - 1], pipex.proc[i].cmd);
		else if (pipex.proc[i].pid == 0)
			do_child_middle(pipex.proc[i - 1].pfd, pipex.proc[i].pfd, pipex.proc[i].cmd);
		else
		{
			if (i > 0)
				close_pipe(pipex.proc, i - 1);
		}
		i++;
	}
	do_waitpid_pipex(pipex.proc, argc - 3);
	return (0);
}

// ./pipex infile "grep a1" "wc -l" outfile
