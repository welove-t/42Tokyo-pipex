/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:59:52 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 14:58:01 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*get_cmd(char *cmd);
static char	*get_path(char *cmd);

char	**get_cmd_array(char *cmd_line)
{
	char	**r_str_array;

	r_str_array = do_split(cmd_line, CMD_LINE_SEP);
	if (ft_strchr(r_str_array[0], ENV_SELL_PATH))
		r_str_array[0] = get_path(r_str_array[0]);
	else
		r_str_array[0] = get_cmd(r_str_array[0]);
	return (r_str_array);
}

static char	*get_cmd(char *cmd)
{
	int		i_env_path;
	int		i;
	char	**path_array;
	char	*r_str_path;

	cmd = do_strjoin(CMD_PATH, cmd);
	i_env_path = get_env_index(ENV_PATH_NAME, ENV_PATH_START);
	path_array = do_split(&environ[i_env_path][ENV_PATH_START], ENV_PATH_SEP);
	i = 0;
	while (path_array[i])
	{
		r_str_path = do_strjoin(path_array[i], cmd);
		if (!access(r_str_path, X_OK))
			return (r_str_path);
		free(r_str_path);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd)
{
	if (!access(cmd, X_OK))
		return (cmd);
	return (NULL);
}

int	get_env_index(const char *key, int index_start)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], key, index_start))
			return (i);
		i++;
	}
	return (0);
}
