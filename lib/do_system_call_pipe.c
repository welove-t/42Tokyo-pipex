/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_system_call_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:08:30 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 16:17:20 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pipe(int fd[2])
{
	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	do_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

void	do_execve(char **cmd_argv)
{
	if (execve(cmd_argv[0], cmd_argv, environ) < 0)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

pid_t	do_fork(void)
{
	pid_t	r_pid;

	r_pid = fork();
	if (r_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (r_pid);
}

