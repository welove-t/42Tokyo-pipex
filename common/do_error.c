/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:27:10 by terabu            #+#    #+#             */
/*   Updated: 2023/02/15 09:25:57 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	put_error(char *error_msg)
{
	printf("%s\n", error_msg);
}

void	error_not_exist_cmd(char *cmd)
{
	char	*shell_name;
	char	*s1;
	char	*s2;
	char	*s3;
	int		i_env_shell;

	i_env_shell = get_env_index(ENV_SHELL_NAME, ENV_SHELL_START);
	shell_name = ft_strrchr(environ[i_env_shell], ENV_SELL_PATH);
	s1 = ft_strjoin(shell_name + 1, ERR_SEP);
	s2 = ft_strjoin(ERR_CMD_NOT_FOUND, ERR_SEP);
	s3 = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_strjoin(s3, cmd);
	free(s3);
	put_error(s1);
	free(s1);
}