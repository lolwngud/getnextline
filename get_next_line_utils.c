/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:08:42 by juhypark          #+#    #+#             */
/*   Updated: 2022/12/24 17:03:32 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

char	*ft_strdup(const char *src)
{
	char	*new_src;
	int		i;
	int		l;

	i = 0;
	while (src[i] != 0)
		i++;
	l = i + 1;
	new_src = (char *)malloc(l * sizeof(char));
	if (!(new_src))
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = 0;
	return (new_src);
}

char	*ft_strcat(char *dest, char const *src)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (dest[i] != 0)
		i++;
	k = 0;
	while (src[k] != 0)
		dest[i++] = src[k++];
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[0] = 0;
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*ptr;
	size_t	i;

	ch = (char)c;
	ptr = (char *)s;
	i = 0;
	while (ptr[i] != 0)
	{
		if (ptr[i] == ch)
			return (&ptr[i]);
		else
			i++;
	}
	if (ch == 0)
		return (&ptr[i]);
	return (0);
}
