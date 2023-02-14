/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/14 13:06:32 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child(int i_fd[], char *outfile, char **cmd)
{
	int	fd;

	close(i_fd[1]);
	// input pipe
	close(STDIN_FILENO);
	do_dup2(i_fd[0], STDIN_FILENO);

	// output file
	fd = do_open_normal_write(outfile);
	do_dup2(fd, STDOUT_FILENO);
	do_execve(cmd);
	close(i_fd[0]);
}

void	do_parent(int o_fd[], char *infile, char **cmd)
{
	int	fd;

	close(o_fd[0]);
	// input infile
	fd = do_open(infile, O_RDONLY);
	close(STDIN_FILENO);
	do_dup2(fd, STDIN_FILENO);

	// output pipe
	close(STDOUT_FILENO);
	do_dup2(o_fd[1], STDOUT_FILENO);
	do_execve(cmd);
	close(fd);
	do_wait();
}

int	main(int argc, char *argv[])
{
	char	**cmd_line1;
	char	**cmd_line2;
	int		fd[2];
	pid_t	pid;

	(void)argc;
	cmd_line1 = get_cmd_array(argv[2]);
	cmd_line2 = get_cmd_array(argv[3]);
	pipe(fd);
	pid = do_fork();
	if (pid)
		do_parent(fd, argv[1], cmd_line1);
	else
		do_child(fd, argv[4], cmd_line2);
	return (0);
}


// ./pipex infile "grep a1" "wc -l" outfile
