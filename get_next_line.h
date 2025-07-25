/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorazafi <zorazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:29:35 by zorazafi          #+#    #+#             */
/*   Updated: 2025/07/25 02:32:53 by zorazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
void	fill_str(char *res, char *s1, char *s2);

#endif
