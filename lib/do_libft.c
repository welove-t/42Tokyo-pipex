/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:47:25 by terabu            #+#    #+#             */
/*   Updated: 2023/02/22 15:09:13 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*do_strjoin(char *s1, char *s2)
{
	char	*r_str;

	r_str = ft_strjoin(s1, s2);
	if (r_str == NULL)
		exit(EXIT_FAILURE);
	return (r_str);
}

char	*do_strdup(char *s)
{
	char	*r_str;

	r_str = ft_strdup(s);
	if (r_str == NULL)
		exit(EXIT_FAILURE);
	return (r_str);
}

char	**do_split(char *str, char sep)
{
	char	**r_str_array;

	r_str_array = ft_split(str, sep);
	if (r_str_array == NULL)
		exit(EXIT_FAILURE);
	return (r_str_array);
}
