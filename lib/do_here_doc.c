/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:43:09 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 12:37:01 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	input_here_doc(t_pipex *pipex, int fd)
{
	char	*buff;

	while (1)
	{
		write(1, "heredoc > ", 11);
		buff = get_next_line(0);
		if (!buff)
			exit(1);
		if (!ft_strncmp(buff, pipex->limiter, ft_strlen(pipex->limiter)))
			break ;
		write(fd, buff, ft_strlen(buff));
		free (buff);
	}
	free(buff);
}
