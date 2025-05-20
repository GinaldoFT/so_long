/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:35:02 by ginfranc          #+#    #+#             */
/*   Updated: 2025/05/02 08:16:54 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 42

static void	free_ptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*extract_line(char **backup, char buffer[])
{
	char	*line;
	int		i;

	i = 0;
	while ((*backup)[i] && (*backup)[i] != '\n')
		i++;
	if ((*backup)[i] == '\n')
		i++;
	line = ft_substr(*backup, 0, i);
	if (!line)
	{
		free_ptr(backup);
		return (NULL);
	}
	buffer[0] = '\0';
	ft_strlcpy(buffer, *backup + i, ft_strlen(*backup + i) + 1);
	free_ptr(backup);
	return (line);
}

static int	read_into_backup(int fd, char buffer[], char **backup)
{
	char	*tmp;
	int		bytes;

	bytes = 1;
	while (!ft_strchr(*backup, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes);
		buffer[bytes] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(tmp, buffer);
		free_ptr(&tmp);
		if (!*backup)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*backup;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = malloc(ft_strlen(buffer) + 1);
	if (!backup)
		return (NULL);
	ft_strlcpy(backup, buffer, ft_strlen(buffer) + 1);
	buffer[0] = '\0';
	if (read_into_backup(fd, buffer, &backup) == -1)
	{
		free_ptr(&backup);
		return (NULL);
	}
	if (!*backup)
	{
		free_ptr(&backup);
		return (NULL);
	}
	return (extract_line(&backup, buffer));
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	int	fd;
	char	*text;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		text = get_next_line(fd);
		if (!text)
			break;
		printf("%s", text);
		free(text);
	}
	close(fd);
	return (0);
}
*/
