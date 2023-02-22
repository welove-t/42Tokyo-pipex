/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:41:51 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 14:54:43 by terabu           ###   ########.fr       */
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
# include "../lib/get_next_line/get_next_line.h"

# define ENV_PATH_NAME				"PATH="
# define ENV_SHELL_NAME				"SHELL="
# define ENV_PATH_SEP				':'
# define ENV_SELL_PATH				'/'
# define CMD_PATH					"/"
# define CMD_LINE_SEP				' '
# define HERE_DOC_NAME				"here_doc"
# define HERE_DOC_FILE				".here_doc"
# define HERE_DOC_CNT				8

// MAGIC NUMBER
# define ENV_PATH_START					5
# define ENV_SHELL_START				6
# define ARGS_INFILE_PATH				1
# define ARGS_OUTFILE_PATH_WEI			1
# define ARGS_CMD_CNT_WEI_NOMAL			3
# define ARGS_CMD_CNT_WEI_HERE_DOC		4
# define ARGS_LIMITER					2
# define ARGS_MIN_NORMAL				5
# define ARGS_MIN_HERE_DOC				6
# define ARGS_CMD_WEI_NOMAL				2
# define ARGS_CMD_WEI_HERE_DOC			3

// ERROR
# define ERR_CMD_NOT_FOUND	"command not found"
# define ERR_SEP			": "

typedef struct s_proc
{
	pid_t	pid;
	int		pfd[2];
	char	*cmd;
}	t_proc;

typedef struct t_pipex
{
	t_proc	*proc;
	char	*infile_name;
	char	*outfile_name;
	char	*limiter;
	int		min_arg_size;
	int		cnt_proc;
}	t_pipex;

extern char	**environ;

// initialize
void	initialize(int argc, char *argv[], t_pipex *pipex);

// do_libft
char	*do_strjoin(char *s1, char *s2);
char	*do_strdup(char *s);
char	**do_split(char *str, char sep);

// do_system_call(file)
int		do_open_read(const char *file_path);
int		do_open_write(const char *file_path);
int		do_open_write_append(const char *file_path);
void	do_close(int fd);
void	do_unlink(char *filepath);

// do_system_call(pipe)
void	do_pipe(int fd[2]);
void	do_dup2(int old_fd, int new_fd);
void	do_execve(char **cmd_argv);
pid_t	do_fork(void);
void	do_wait(void);

// do_error
void	error_not_exist_cmd(char *cmd);

// do_dup_close
void	redirect_in_dup_close(t_pipex *pipex);
void	output_pipe_dup_close(int fd[2]);
void	input_pipe_dup_close(int fd[2]);
void	redirect_out_dup_close(t_pipex *pipex);

// get_cmd_line
char	**get_cmd_array(char *cmd_line);
int		get_env_index(const char *key, int index_start);

// do_here_doc
void	do_here_doc_in(t_pipex *pipex, int idx_proc);
void	input_here_doc(t_pipex *pipex, int fd);


// finalize
void	finalize(t_pipex *pipex);
void	close_pipe(t_proc *proc, int idx_proc);


#endif
