/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorazafi <zorazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:35:18 by zorazafi          #+#    #+#             */
/*   Updated: 2025/07/25 05:39:18 by zorazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*read_and_stash(int fd, char *stash, char *buf)
{
	ssize_t	bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*extract_next_line(char *stash)
{
	size_t	i;
	char	*next;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	next = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	if (!next || !*next)
	{
		free(next);
		next = NULL;
	}
	stash[i + 1] = '\0';
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_and_stash(fd, stash, buf);
	free(buf);
	if (!line)
		return (NULL);
	stash = extract_next_line(line);
	return (line);
}
