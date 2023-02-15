/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:41:51 by terabu            #+#    #+#             */
/*   Updated: 2023/02/15 14:10:42 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../common/libft/libft.h"

# define ENV_PATH_NAME		"PATH="
# define ENV_SHELL_NAME		"SHELL="
# define ENV_PATH_START		5
# define ENV_SHELL_START	6
# define ENV_PATH_SEP		':'
# define ENV_SELL_PATH		'/'
# define CMD_PATH			"/"
# define CMD_LINE_SEP		' '

// ERROR
# define ERR_CMD_NOT_FOUND	"command not found"
# define ERR_SEP			": "

extern char	**environ;

// do_libft
char	*do_strjoin(char *s1, char *s2);
char	*do_strdup(char *s);
char	**do_split(char *str, char sep);

// do_system_call(file)
int		do_open_read(const char *file_path);
int		do_open_normal_write(const char *file_path);
void	do_close(int fd);

// do_system_call(pipe)
void	do_pipe(int fd[2]);
void	do_dup2(int old_fd, int new_fd);
void	do_execve(char **cmd_argv);
pid_t	do_fork(void);
void	do_wait(void);

// do_error
void	error_not_exist_cmd(char *cmd);

// get_cmd_line
char	**get_cmd_array(char *cmd_line);
int		get_env_index(const char *key, int index_start);

#endif
