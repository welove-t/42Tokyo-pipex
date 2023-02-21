/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:25:27 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 15:57:55 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_waitpid_pipex(t_pipex *pipex, int cnt_proc)
{
	int		i;
	int		status;
	pid_t	pid;

	i = 0;
	while (i < cnt_proc)
	{
		pid = waitpid(pipex[i].pid, &status, 0);
		if (pid < 0)
			perror("waitpid");
		i++;
	}
}
