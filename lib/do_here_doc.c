/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:43:09 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 20:31:22 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	do_here_doc_in(t_pipex *pipex)
{
	char	*buff;

	while (1)
	{
		write(1, "> heredoc", 10);
		buff = get_next_line(0);
		if (!ft_strncmp(buff, pipex->limiter, ft_strlen(pipex->limiter)))
			break ;
		free (buff);
	}
	free(buff);
}

// void	do_here_doc_out(t_pipex *pipex)
// {
// 	char	*buff;

// 	while (1)
// 	{
// 		write(1, "> heredoc", 9);
// 		buff = get_next_line(0);
// 		if (!ft_strncmp(buff, pipex->limiter, ft_strlen(pipex->limiter)))
// 			break ;
// 		free (buff);
// 	}
// 	free(buff);
// }
