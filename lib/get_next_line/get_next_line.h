/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:37:08 by terabu            #+#    #+#             */
/*   Updated: 2023/02/21 20:36:58 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 32

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strldup_gnl(const char *s, size_t len);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
