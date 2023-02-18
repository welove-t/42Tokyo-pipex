/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:16 by terabu            #+#    #+#             */
/*   Updated: 2023/02/18 14:16:18 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipex	*set_init_pipex(int cmd_cnt, char *argv[])
{
	int		i;
	t_pipex	*pipex;

	pipex = ft_calloc((cmd_cnt + 1), sizeof(t_pipex));
	if (!pipex)
		exit(1);
	i = 0;
	while (i < cmd_cnt)
	{
		pipex[i].cmd = argv[i + 2];
		i++;
	}
	return (pipex);
}

