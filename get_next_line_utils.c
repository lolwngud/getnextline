/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:01:30 by juhypark          #+#    #+#             */
/*   Updated: 2022/12/29 16:49:02 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *backup, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (backup)
		while (backup[++i] != '\0')
			str[i] = backup[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(backup) + ft_strlen(buff)] = '\0';
	free(backup);
	return (str);
}
