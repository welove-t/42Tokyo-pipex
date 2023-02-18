/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/18 14:40:16 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_last_child(int i_fd[], char *outfile, char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	input_pipe_dup_close(i_fd);
	redirect_out_dup_close(outfile);
	do_execve(cmd_line);
}

void	do_first_child(int o_fd[], char *infile, char *cmd)
{
	char	**cmd_line;

	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	redirect_in_dup_close(infile);
	output_pipe_dup_close(o_fd);
	do_execve(cmd_line);
	do_wait();
}

int	main(int argc, char *argv[])
{
	// int		fd[2];
	// pid_t	pid;
	t_pipex	*pipex;

	if (argc < 5)
		return (0);
	pipex = set_init_pipex(argc - 3, argv);
	printf("%s\n", pipex[0].cmd);
	printf("%s\n", pipex[1].cmd);
	printf("%s\n", pipex[2].cmd);
	printf("%d\n", pipex[0].pid);
	// do_pipe(fd);
	// pid = do_fork();
	// if (pid)
	// 	do_parent(fd, argv[1], argv[2]);
	// else
	// 	do_child(fd, argv[4], argv[3]);
	// return (0);
}


// ./pipex infile "grep a1" "wc -l" outfile
