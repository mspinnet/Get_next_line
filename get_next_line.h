/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:57:36 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/11 13:52:48 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int		linedo(int fd, char **line, char *buf);
void	lineposle(int fd, char **line, char *buf);
int		circle(int fd, char **line, char *buf);
int		get_next_line(int fd, char **line);

#endif
