/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:25:37 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/20 11:25:38 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# if !BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		len_count(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_strchr(char *buffer, char chr);
char	*splitter(char *buffer, int size);
char	*remain(char *buffer, int size);
char	*read_func(int fd, char *buffer);

#endif
