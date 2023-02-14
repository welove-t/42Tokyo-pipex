/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_system_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:08:30 by terabu            #+#    #+#             */
/*   Updated: 2023/02/14 13:12:48 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	do_open(const char *file_path, int flag)
{
	int	r_fd;

	r_fd = open(file_path, flag);
	if (r_fd < 0)
		exit(1);
	return (r_fd);
}

int	do_open_normal_write(const char *file_path)
{
	int	r_fd;

	r_fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (r_fd < 0)
		exit(1);
	return (r_fd);
}
// int	*do_pipe(void)
// {
// 	int	fildes[2];

// 	if (pipe(fildes) < 0)
// 		exit(1);
// 	return (fildes);
// }

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
