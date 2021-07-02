/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:24:13 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/12 15:40:26 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)malloc(count * size);
	if (NULL == str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char*)&s[i]);
	}
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else
			return ((char*)&s[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char*)malloc(sizeof(char) * (i + j + 1));
	if (NULL == str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		*((char*)s + i) = 0;
		i++;
	}
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			l;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	l = i;
	i = 0;
	s2 = (char*)malloc(sizeof(char) * len + 1);
	if (NULL == s2)
		return (NULL);
	while (len > 0 && start <= l)
	{
		s2[i] = s[start];
		i++;
		start++;
		len--;
	}
	s2[i] = '\0';
	return (s2);
}
