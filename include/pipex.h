/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:41:51 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 16:36:08 by terabu           ###   ########.fr       */
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
# include "../lib/libft/libft.h"

# define ENV_PATH_NAME		"PATH="
# define ENV_SHELL_NAME		"SHELL="
# define ENV_PATH_START		5
# define ENV_SHELL_START	6
# define ENV_PATH_SEP		':'
# define ENV_SELL_PATH		'/'
# define CMD_PATH			"/"
# define CMD_LINE_SEP		' '
# define HERE_DOC			"here_doc"
# define HERE_DOC_CNT		8

// ERROR
# define ERR_CMD_NOT_FOUND	"command not found"
# define ERR_SEP			": "

typedef struct s_pipex
{
	pid_t	pid;
	int		pfd[2];
	char	*cmd;
}	t_pipex;

extern char	**environ;

// initialize
t_pipex	*set_init_pipex(int cmd_cnt, char *argv[]);

// do_libft
char	*do_strjoin(char *s1, char *s2);
char	*do_strdup(char *s);
char	**do_split(char *str, char sep);

// do_system_call(file)
int		do_open_normal_read(const char *file_path);
int		do_open_normal_write(const char *file_path);
int		do_open_heredoc_read(void);
int		do_open_heredoc_write(const char *file_path);
void	do_close(int fd);

// do_system_call(pipe)
void	do_pipe(int fd[2]);
void	do_dup2(int old_fd, int new_fd);
void	do_execve(char **cmd_argv);
pid_t	do_fork(void);
void	do_wait(void);

// do_error
void	error_not_exist_cmd(char *cmd);

// do_dup_close
void	redirect_in_dup_close(const char *filepath);
void	output_pipe_dup_close(int fd[2]);
void	input_pipe_dup_close(int fd[2]);
void	redirect_out_dup_close(const char *filepath);

// get_cmd_line
char	**get_cmd_array(char *cmd_line);
int		get_env_index(const char *key, int index_start);

void	do_waitpid_pipex(t_pipex *pipex, int cnt_proc);


#endif
