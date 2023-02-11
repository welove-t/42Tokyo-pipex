/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:57:28 by terabu            #+#    #+#             */
/*   Updated: 2023/02/11 16:06:00 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	char	**cmd_line;
	int		i;
	int		fd[2];

	(void)argc;
	cmd_line = get_cmd_array(argv[2]);
	i = 0;

	fd[0] = open(argv[1], O_RDONLY);
	close(0);
	dup2(fd[0], 0);
	close(fd[0]);
	execve(cmd_line[0], cmd_line, environ);
	return (0);
}

