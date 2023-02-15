/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/15 14:11:41 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child(int i_fd[], char *outfile, char *cmd)
{
	int		fd;
	char	**cmd_line;

	do_close(i_fd[1]);
	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	// input pipe
	do_close(STDIN_FILENO);
	do_dup2(i_fd[0], STDIN_FILENO);

	// output file
	fd = do_open_normal_write(outfile);
	do_dup2(fd, STDOUT_FILENO);
	do_execve(cmd_line);
	do_close(i_fd[0]);
}

void	do_parent(int o_fd[], char *infile, char *cmd)
{
	int		fd;
	char	**cmd_line;

	do_close(o_fd[0]);
	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	// input infile
	fd = do_open_read(infile);
	do_close(STDIN_FILENO);
	do_dup2(fd, STDIN_FILENO);

	// output pipe
	do_close(STDOUT_FILENO);
	do_dup2(o_fd[1], STDOUT_FILENO);
	do_execve(cmd_line);
	do_close(fd);
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
