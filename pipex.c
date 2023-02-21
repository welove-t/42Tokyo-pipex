/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 16:29:50 by terabu           ###   ########.fr       */
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

void	close_pipe(t_pipex *pipex, int i)
{
	do_close(pipex[i].pfd[0]);
	do_close(pipex[i].pfd[1]);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_pipex	*pipex;

	pipex = set_init_pipex(argc - 3, argv);
	if (argc < 5)
		return (0);
	i = 0;
	while (i < argc - 3)
	{
		if (i < argc - 4)
			do_pipe(pipex[i].pfd);
		pipex[i].pid = do_fork();
		if (i == 0 && pipex[i].pid == 0)
			do_child_first(pipex[i].pfd, argv[1], pipex[i].cmd);
		else if (i == argc - 4 && pipex[i].pid == 0)
			do_child_last(pipex[i - 1].pfd, argv[argc - 1], pipex[i].cmd);
		else if (pipex[i].pid == 0)
			do_child_middle(pipex[i - 1].pfd, pipex[i].pfd, pipex[i].cmd);
		else
		{
			if (i > 0)
				close_pipe(pipex, i - 1);
		}
		i++;
	}
	do_waitpid_pipex(pipex, argc - 3);
	return (0);
}

// ./pipex infile "grep a1" "wc -l" outfile
