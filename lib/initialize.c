/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:16 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 15:09:13 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_pipex_normal(int cnt_cmd, char *argv[], t_pipex *pipex);
static void	set_pipex_heredoc(int cnt_cmd, char *argv[], t_pipex *pipex);

void	initialize(int argc, char *argv[], t_pipex *pipex)
{
	if (argc < ARGS_MIN_NORMAL)
		return ;
	if (!ft_strncmp(argv[ARGS_INFILE_PATH], HERE_DOC_NAME, HERE_DOC_CNT))
		set_pipex_heredoc(argc - ARGS_CMD_CNT_WEI_HERE_DOC, argv, pipex);
	else
		set_pipex_normal(argc - ARGS_CMD_CNT_WEI_NOMAL, argv, pipex);
	pipex->outfile_name = argv[argc - ARGS_OUTFILE_PATH_WEI];
}

static void	set_pipex_normal(int cnt_cmd, char *argv[], t_pipex *pipex)
{
	t_proc	*proc;
	int		i;

	proc = ft_calloc((cnt_cmd + 1), sizeof(t_proc));
	if (!proc)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < cnt_cmd)
	{
		proc[i].cmd = argv[i + ARGS_CMD_WEI_NOMAL];
		i++;
	}
	pipex->cnt_proc = cnt_cmd;
	pipex->infile_name = argv[ARGS_INFILE_PATH];
	pipex->min_arg_size = ARGS_MIN_NORMAL;
	pipex->proc = proc;
}

static void	set_pipex_heredoc(int cnt_cmd, char *argv[], t_pipex *pipex)
{
	t_proc	*proc;
	int		i;

	proc = ft_calloc((cnt_cmd + 1), sizeof(t_proc));
	if (!proc)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < cnt_cmd)
	{
		proc[i].cmd = argv[i + ARGS_CMD_WEI_HERE_DOC];
		i++;
	}
	pipex->cnt_proc = cnt_cmd;
	pipex->infile_name = argv[ARGS_INFILE_PATH];
	pipex->limiter = argv[ARGS_LIMITER];
	pipex->min_arg_size = ARGS_MIN_HERE_DOC;
	pipex->proc = proc;
}
