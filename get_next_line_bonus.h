/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhypark <juhypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:59:14 by juhypark          #+#    #+#             */
/*   Updated: 2022/12/29 16:43:42 by juhypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
int		ft_read_backup(int fd, char **backup);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *backup, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *backup);
char	*ft_new_backup(char *backup);
#endif
