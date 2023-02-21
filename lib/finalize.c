/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:25:27 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 19:52:51 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_waitpid_pipex(t_proc *proc, int cnt_proc)
{
	int		i;
	int		status;
	pid_t	pid;

	i = 0;
	while (i < cnt_proc)
	{
		pid = waitpid(proc[i].pid, &status, 0);
		if (pid < 0)
			perror("waitpid");
		i++;
	}
}

void	close_pipe(t_proc *proc, int idx_proc)
{
	if (idx_proc < 1)
		return ;
	do_close(proc[idx_proc - 1].pfd[0]);
	do_close(proc[idx_proc - 1].pfd[1]);
}
