/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dup_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:31:04 by terabu            #+#    #+#             */
/*   Updated: 2023/02/18 12:56:24 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in_dup_close(char *infile)
{
	int	fd;

	fd = do_open_read(infile);
	do_dup2(fd, STDIN_FILENO);
	do_close(fd);
}

void	output_pipe_dup_close(int fd[2])
{
	do_close(fd[0]);
	do_dup2(fd[1], STDOUT_FILENO);
	do_close(fd[1]);
}

void	input_pipe_dup_close(int fd[2])
{
	do_close(fd[1]);
	do_dup2(fd[0], STDIN_FILENO);
	do_close(fd[0]);
}

void	redirect_out_dup_close(char *outfile)
{
	int	fd;

	fd = do_open_normal_write(outfile);
	do_dup2(fd, STDOUT_FILENO);
	do_close(fd);
}
