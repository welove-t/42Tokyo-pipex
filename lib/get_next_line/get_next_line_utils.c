/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:37:14 by terabu            #+#    #+#             */
/*   Updated: 2022/11/08 12:44:38 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char	*ft_strldup(const char *s, size_t len)
{
	char	*heap;
	size_t	i;

	heap = (char *)malloc(sizeof(char) * (len + 1));
	if (heap == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		heap[i] = s[i];
		i++;
	}
	heap[i] = '\0';
	return (heap);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	if (s == NULL)
		return (NULL);
	cc = (char)c;
	while (*s != cc && *s != '\0')
		s++;
	if (*s == cc)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*heap;
	char	*temp;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strldup(s1, ft_strlen(s1)));
	if (s1 == NULL)
		return (ft_strldup(s2, ft_strlen(s2)));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	heap = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (heap == NULL)
		return (NULL);
	temp = heap;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	heap[len_s1 + len_s2] = '\0';
	return (heap);
}
