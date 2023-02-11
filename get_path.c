/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:59:52 by terabu            #+#    #+#             */
/*   Updated: 2023/02/11 14:59:34 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_env_index_path(void);

char	*get_path(char *cmd)
{
	int		i_env_path;
	int		i;
	char	**path_array;
	char	*r_str_path;

	cmd = do_strjoin(CMD_PATH, cmd);
	i_env_path = get_env_index_path();
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
	return ("NG");
}

// int	check_path_access(char *str_path_array)
// {
// 	char	**r_str_array;

// }

// char	**get_env_path_array()
// {

// }

static int	get_env_index_path(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], ENV_PATH_NAME, ENV_PATH_START))
			return (i);
		i++;
	}
	return (0);
}
