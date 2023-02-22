/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dup_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:31:04 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 16:16:29 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in_dup_close(t_pipex *pipex)
{
	int		fd;
	char	*filepath;

	filepath = pipex->infile_name;
	if (!ft_strncmp(pipex->infile_name, HERE_DOC_NAME, HERE_DOC_CNT))
	{
		fd = do_open_write(HERE_DOC_FILE);
		input_here_doc(pipex, fd);
		do_close(fd);
		filepath = HERE_DOC_FILE;
	}
	fd = do_open_read(filepath);
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

	if (!ft_strncmp(pipex->infile_name, HERE_DOC_NAME, HERE_DOC_CNT))
		fd = do_open_write_append(pipex->outfile_name);
	else
		fd = do_open_write(pipex->outfile_name);
	do_dup2(fd, STDOUT_FILENO);
	do_close(fd);
}
