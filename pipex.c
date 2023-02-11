/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/11 15:13:44 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	char	*path;

	(void)argc;
	path = get_path(argv[1]);
	printf("%s\n", path);
	// char	*x_exe[3];
	// int		fd[2];

	// x_exe[0] = "/usr/bin/grep";
	// printf("%s\n", environ[7]);

	// // x_exe[0] = "/bin/ls";
	// // x_exe[1] = "-l";
	// x_exe[1] = "a1";
	// x_exe[2] = NULL;

	// close(0);
	// close(fd[0]);
	// fd[0] = open(argv[1], O_RDONLY);
	// dup2(fd[0], 0);
	// execve(x_exe[0], x_exe, environ);
}


/*
処理フロー

1. コマンドの有効性確認



*/
