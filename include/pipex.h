/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:41:51 by terabu            #+#    #+#             */
/*   Updated: 2023/02/14 12:25:56 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../common/libft/libft.h"

# define ENV_PATH_NAME		"PATH="
# define ENV_PATH_START		5
# define ENV_PATH_SEP		':'
# define CMD_PATH			"/"
# define CMD_LINE_SEP		' '

extern char	**environ;

// do_libft
char	*do_strjoin(char *s1, char *s2);
char	*do_strdup(char *s);
char	**do_split(char *str, char sep);

// do_system_call
int		do_open(const char *file_path, int flag);
int		*do_pipe(void);
void	do_dup2(int old_fd, int new_fd);
void	do_execve(char **cmd_argv);
pid_t	do_fork(void);
void	do_wait(void);

// get_cmd_line
char	**get_cmd_array(char *cmd_line);

#endif
