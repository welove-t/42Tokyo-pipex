/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 07:55:48 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_child_last(int i_fd[], char *outfile, char *cmd)
{
	char	**cmd_line;

	printf("last\n");
	printf("last[fd]:%d %d\n", i_fd[0], i_fd[1]);
	printf("last[cmd]:%s\n",cmd);
	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	input_pipe_dup_close(i_fd);
	redirect_out_dup_close(outfile);
	do_execve(cmd_line);
}

void	do_child_middle(int i_fd[], int o_fd[], char *cmd)
{
	char	**cmd_line;

	printf("middle\n");
	printf("middle[fd]:%d %d\n", i_fd[0], i_fd[1]);
	printf("middle[fd]:%d %d\n", o_fd[0], o_fd[1]);
	printf("middle[cmd]:%s\n",cmd);
	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	input_pipe_dup_close(i_fd);
	output_pipe_dup_close(o_fd);
	do_execve(cmd_line);
}

void	do_child_first(int o_fd[], char *infile, char *cmd)
{
	char	**cmd_line;

	printf("first\n");
	printf("first[fd]:%d %d\n", o_fd[0], o_fd[1]);
	printf("first[cmd]:%s\n",cmd);
	cmd_line = get_cmd_array(cmd);
	if (!cmd_line[0])
		return (error_not_exist_cmd(cmd));
	redirect_in_dup_close(infile);
	output_pipe_dup_close(o_fd);
	do_execve(cmd_line);
}

void	close_pipe(t_pipex *pipex, int i)
{
	do_close(pipex[i].pfd[0]);
	do_close(pipex[i].pfd[1]);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_pipex	*pipex;

	if (argc < 5)
		return (0);
	pipex = set_init_pipex(argc - 3, argv);
	i = 0;
	while (i < argc - 3)
	{
		if (i < argc - 4)
			do_pipe(pipex[i].pfd);
		pipex[i].pid = do_fork();
		if (i == 0 && pipex[i].pid == 0)
			do_child_first(pipex[i].pfd, argv[1], pipex[i].cmd);
		else if (i == argc - 4 && pipex[i].pid == 0)
			do_child_last(pipex[i - 1].pfd, argv[argc - 1], pipex[i].cmd);
		else if (pipex[i].pid == 0)
			do_child_middle(pipex[i - 1].pfd, pipex[i].pfd, pipex[i].cmd);
		else
		{
			if (i > 0)
				close_pipe(pipex, i - 1);
		}
		i++;
	}
	return (0);
}


// ./pipex infile "grep a1" "wc -l" outfile
