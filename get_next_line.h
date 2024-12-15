/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnegron <nnegron@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:40:56 by nnegron           #+#    #+#             */
/*   Updated: 2024/12/12 20:51:04 by nnegron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	charchar(char *s, char c);
int		t_free(char *s);
char	*init_empty_string(void);
void	ft_next_line(char **buffer, int last_new_line);
ssize_t	ft_fill_line(char **buffer, int fd);
char	*get_next_line(int fd);

#endif
