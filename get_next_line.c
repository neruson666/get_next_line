/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnegron <nnegron@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:05:09 by nnegron           #+#    #+#             */
/*   Updated: 2024/12/13 10:58:47 by nnegron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char *s)
{
	if (s)
		free(s);
	s = NULL;
	return (0);
}

char	*init_empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

void	ft_next_line(char **buffer, int last_new_line)
{
	char	*temp;

	temp = *buffer;
	*buffer = ft_substr(*buffer, last_new_line, ft_strlen(*buffer));
	free(temp);
	return ;
}

ssize_t	ft_fill_line(char **buffer, int fd)
{
	ssize_t	count;
	char	*read_buff;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	if (!(*buffer))
		*buffer = init_empty_string();
	if (!(*buffer))
		return (0);
	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (free(buffer), 0);
	count = read(fd, read_buff, BUFFER_SIZE);
	while (count > 0)
	{
		read_buff[count] = '\0';
		*buffer = ft_strjoin(*buffer, read_buff);
		if (charchar(*buffer, '\n') >= 0)
			break ;
		count = read(fd, read_buff, BUFFER_SIZE);
	}
	free(read_buff);
	if (count < 0)
		return (ft_free(*buffer));
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			last_new_line;
	char		*line;

	if (BUFFER_SIZE >= INT_MAX || !ft_fill_line(&buffer, fd))
	{
		buffer = NULL;
		line = NULL;
		return (free(buffer), free(line), NULL);
	}
	last_new_line = charchar(buffer, '\n');
	if (last_new_line >= 0)
	{
		line = ft_substr(buffer, 0, last_new_line + 1);
		ft_next_line(&buffer, last_new_line + 1);
	}
	else
	{
		line = ft_substr(buffer, 0, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
	}
	if (*line == '\0')
		return (ft_free(line), ft_free(buffer), NULL);
	return (line);
}
