/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:24:13 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/14 12:56:12 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	const char		*str2;

	i = 0;
	str1 = dst;
	str2 = src;
	if (dst == '\0' && src == '\0')
		return (NULL);
	if (src > dst)
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	else
		while (len > 0)
		{
			str1[len - 1] = str2[len - 1];
			len--;
		}
	return (dst);
}

int		linedo(int fd, char **line, char *buf)
{
	int		rd;
	char	*clean;

	clean = NULL;
	if (**line != '\0')
		clean = *line;
	*line = ft_strjoin(*line, buf);
	if (clean != NULL)
		free(clean);
	ft_bzero(buf, BUFFER_SIZE);
	rd = read(fd, buf, BUFFER_SIZE);
	if (rd == 0)
		return (0);
	if (rd < 0)
		return (-1);
	return (1);
}

void	lineposle(int fd, char **line, char *buf)
{
	char	*clean;
	char	*clean1;
	size_t	i;
	char	*str;

	(void)fd;
	str = ft_strchr(buf, '\n');
	i = str - buf;
	clean = NULL;
	clean1 = ft_substr(buf, 0, i);
	if (**line != '\0')
		clean = *line;
	*line = ft_strjoin(*line, clean1);
	if (clean != NULL)
		free(clean);
	free(clean1);
	ft_memmove(buf, &buf[i + 1], BUFFER_SIZE - i - 1);
	ft_bzero(&buf[BUFFER_SIZE - i - 1], i + 1);
}

int		circle(int fd, char **line, char *buf)
{
	int res;

	res = 0;
	while (buf)
		if (ft_strchr(buf, '\n') == NULL)
		{
			res = linedo(fd, line, buf);
			if (res == 0)
				return (0);
			if (res == -1)
				return (-1);
		}
		else
		{
			lineposle(fd, line, buf);
			return (1);
		}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	int			result;

	if (buf == NULL)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (read(fd, buf, BUFFER_SIZE) < 0 || BUFFER_SIZE <= 0)
		{
			free(buf);
			buf = NULL;
			return (-1);
		}
	}
	*line = "\0";
	result = circle(fd, line, buf);
	if (result == 0 || result == -1 || (result == 1 && *buf == '\0'))
	{
		free(buf);
		buf = NULL;
	}
	return (result);
}
