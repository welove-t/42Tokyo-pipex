/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/18 13:00:44 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child(int i_fd[], char *outfile, char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	input_pipe_dup_close(i_fd);
	redirect_out_dup_close(outfile);
	do_execve(cmd_line);
}

void	do_parent(int o_fd[], char *infile, char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	redirect_in_dup_close(infile);
	output_pipe_dup_close(o_fd);
	do_execve(cmd_line);
	do_wait();
}

int	main(int argc, char *argv[])
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (0);
	do_pipe(fd);
	pid = do_fork();
	if (pid)
		do_parent(fd, argv[1], argv[2]);
	else
		do_child(fd, argv[4], argv[3]);
	return (0);
}


// ./pipex infile "grep a1" "wc -l" outfile
