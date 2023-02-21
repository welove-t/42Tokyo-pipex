/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:16 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 19:38:13 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_pipex_normal(int cmd_cnt, char *argv[], t_pipex *pipex);
static void	set_pipex_heredoc(int cmd_cnt, char *argv[], t_pipex *pipex);

void	initialize(int argc, char *argv[], t_pipex *pipex)
{
	if (argc < 5)
		return ;
	if (!ft_strncmp(argv[1], HERE_DOC, HERE_DOC_CNT))
		set_pipex_heredoc(argc - 4, argv, pipex);
	else
		set_pipex_normal(argc - 3, argv, pipex);
	pipex->outfile_name = argv[argc - 1];
}

static void	set_pipex_normal(int cmd_cnt, char *argv[], t_pipex *pipex)
{
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
	pipex->infile_name = argv[1];
	pipex->min_arg_size = 5;
	pipex->proc = proc;
}

static void	set_pipex_heredoc(int cmd_cnt, char *argv[], t_pipex *pipex)
{
	t_proc	*proc;
	int		i;

	proc = ft_calloc((cmd_cnt + 1), sizeof(t_proc));
	if (!proc)
		exit(1);
	i = 0;
	while (i < cmd_cnt)
	{
		proc[i].cmd = argv[i + 3];
		i++;
	}
	pipex->infile_name = argv[1];
	pipex->here_doc_limiter = argv[2];
	pipex->min_arg_size = 6;
	pipex->proc = proc;
}
