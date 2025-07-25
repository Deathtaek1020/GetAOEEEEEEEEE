/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorazafi <zorazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:29:08 by zorazafi          #+#    #+#             */
/*   Updated: 2025/07/25 04:06:59 by zorazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (!str)
		return (NULL);
	temp = malloc(ft_strlen((char *)str) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!str || start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && str[start + i])
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	fill_str(char *res, char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	if (!res || !s1 || !s2)
		return ;
	i = 0;
	j = 0;
	while (s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	fill_str(res, s1, s2);
	return (res);
}
