/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:16 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 18:02:10 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	set_init_pipex(int cmd_cnt, char *argv[])
{
	t_pipex	pipex;
	t_proc	*proc;
	int		i;

	proc = ft_calloc((cmd_cnt + 1), sizeof(t_proc));
	if (!proc)
		exit(1);
	i = 0;
	while (i < cmd_cnt)
	{
		proc[i].cmd = argv[i + 2];
		i++;
	}
	pipex.proc = proc;
	return (pipex);
}
