/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:25:27 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 15:49:56 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	do_waitpid_pipex(t_proc *proc, int cnt_proc);

void	finalize(t_pipex *pipex)
{
	do_waitpid_pipex(pipex->proc, pipex->cnt_proc);
	if (!ft_strncmp(pipex->infile_name, HERE_DOC_NAME, HERE_DOC_CNT))
		do_unlink(HERE_DOC_FILE);
	free(pipex->proc);
	exit(EXIT_SUCCESS);
}

static void	do_waitpid_pipex(t_proc *proc, int cnt_proc)
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
