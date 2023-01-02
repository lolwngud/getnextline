/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:58:59 by juhypark          #+#    #+#             */
/*   Updated: 2022/12/29 16:50:02 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_backup(char *backup)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

int	ft_read_backup(int fd, char **backup)
{
	char	*buff;
	long	bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(*backup, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[bytes] = '\0';
		*backup = ft_strjoin(*backup, buff);
	}
	free(buff);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_read_backup(fd, &backup[fd]))
	{
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(backup[fd]);
	if (line == NULL)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	backup[fd] = ft_new_backup(backup[fd]);
	return (line);
}
