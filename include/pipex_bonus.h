/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:41:51 by terabu            #+#    #+#             */
/*   Updated: 2023/02/18 14:45:53 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

typedef struct s_pipex
{
	pid_t	pid;
	int		pfd[2];
	char	*cmd;
}	t_pipex;

t_pipex	*set_init_pipex(int cmd_cnt, char *argv[]);

#endif
