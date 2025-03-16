/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:26:49 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/16 14:19:26 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof (char));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_reset(&stash), ft_free_reset(&buffer), NULL);
	if (!buffer)
		return (NULL);
	line = ft_fill_line(fd, buffer, stash);
	ft_free_reset(&buffer);
	if (!line)
	{
		if (stash)
			ft_free_reset(&stash);
		return (NULL);
	}
	stash = ft_clean_line(line);
	return (line);
}

char	*ft_fill_line(int fd, char *buffer, char *stash)
{
	long	cursor;
	char	*temp;

	cursor = 1;
	while (cursor > 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor < 0)
			return (NULL);
		else if (cursor == 0)
			break ;
		buffer[cursor] = 0;
		if (!stash)
		{
			stash = ft_calloc(1, 1);
			if (!stash)
				return (NULL);
		}
		temp = stash;
		stash = gnl_ft_strjoin(temp, buffer);
		ft_free_reset(&temp);
		if (gnl_ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_clean_line(char *line)
{
	long	i;
	char	*stash;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	tmp = gnl_ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!tmp)
	{
		line[i + 1] = '\0';
		return (NULL);
	}
	stash = tmp;
	if (!(*stash))
		ft_free_reset(&stash);
	line[i + 1] = '\0';
	return (stash);
}	

void	ft_free_reset(char **str)
{
	free(*str);
	*str = NULL;
}

/* #include <stdio.h>
int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	str = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		printf("-----ligne %d\n%s", i++, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
} */
