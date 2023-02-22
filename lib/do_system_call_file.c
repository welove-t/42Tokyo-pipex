/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_system_call_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:08:30 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 14:08:50 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	do_open_read(const char *file_path)
{
	int	r_fd;

	r_fd = open(file_path, O_RDONLY);
	if (r_fd < 0)
	{
		perror("open");
		exit(1);
	}
	return (r_fd);
}

int	do_open_write(const char *file_path)
{
	int	r_fd;

	r_fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (r_fd < 0)
	{
		perror("write");
		exit(1);
	}
	return (r_fd);
}

int	do_open_write_append(const char *file_path)
{
	int	r_fd;

	r_fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (r_fd < 0)
	{
		perror("write");
		exit(1);
	}
	return (r_fd);
}

void	do_close(int fd)
{
	if (close(fd) < 0)
	{
		perror("close");
		exit(1);
	}
}

void	do_unlink(char *filepath)
{
	if (unlink(filepath) < 0)
	{
		perror("unlink");
		exit(1);
	}
}
