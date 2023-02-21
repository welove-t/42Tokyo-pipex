/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dup_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:31:04 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 20:28:29 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	redirect_in_dup_close(t_pipex *pipex)
{
	int	fd;

	if (!ft_strncmp(pipex->infile_name, HERE_DOC, HERE_DOC_CNT))
	{
		fd = do_open_heredoc_read();
		do_here_doc_in(pipex);
	}
	else
		fd = do_open_normal_read(pipex->infile_name);
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

void	redirect_out_dup_close(t_pipex *pipex)
{
	int	fd;

	if (!ft_strncmp(pipex->infile_name, HERE_DOC, HERE_DOC_CNT))
		fd = do_open_heredoc_write(pipex->outfile_name);
	else
		fd = do_open_normal_write(pipex->outfile_name);
	do_dup2(fd, STDOUT_FILENO);
	do_close(fd);
}
