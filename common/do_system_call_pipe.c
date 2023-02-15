/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_system_call_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:08:30 by terabu            #+#    #+#             */
/*   Updated: 2023/02/15 14:11:17 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	do_pipe(int fd[2])
{
	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(1);
	}
}

void	do_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) < 0)
		exit(1);
}

void	do_execve(char **cmd_argv)
{
	if (execve(cmd_argv[0], cmd_argv, environ) < 0)
		exit(1);
}

pid_t	do_fork(void)
{
	pid_t	r_pid;

	r_pid = fork();
	if (r_pid < 0)
		exit(1);
	return (r_pid);
}

void	do_wait(void)
{
	int	status;

	if (wait(&status) < 0)
	{
		perror("wait");
		exit(1);
	}
}
