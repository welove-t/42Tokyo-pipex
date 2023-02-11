/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/11 17:04:45 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child(int i_fd[], char *outfile, char **cmd)
{
	int	fd;

	close(i_fd[1]);
	// input pipe
	close(STDIN_FILENO);
	dup2(i_fd[0], STDIN_FILENO);

	// output file
	fd = open(outfile, O_WRONLY);
	dup2(fd, STDOUT_FILENO);
	execve(cmd[0], cmd, environ);
	close(i_fd[0]);
}

void	do_parent(int o_fd[], char *infile, char **cmd)
{
	int	fd;
	// int status;

	close(o_fd[0]);
	// input infile
	fd = open(infile, O_RDONLY);
	close(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);

	// output pipe
	close(STDOUT_FILENO);
	dup2(o_fd[1], STDOUT_FILENO);
	// if (wait(&status) < 0)
	// {
	// 	perror("wait");
	// 	exit(1);
	// }
	execve(cmd[0], cmd, environ);
	close(fd);
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
	pid = fork();

	if (pid)
		do_parent(fd, argv[1], cmd_line1);
	else
	{
		do_child(fd, argv[4], cmd_line2);
	}
	// fd[0] = open(argv[1], O_RDONLY);
	// close(0);
	// dup2(fd[0], 0);
	// close(fd[0]);
	// execve(cmd_line[0], cmd_line, environ);
	return (0);
}
