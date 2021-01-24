/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclerac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:00:08 by aclerac           #+#    #+#             */
/*   Updated: 2021/01/24 16:29:51 by aclerac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	read_buffer(int fd)
{
	ssize_t				read_size;
	char				c;
	static	t_library	tab[FD_LIMIT];

	if (tab[fd].cursor)
		c = tab[fd].buffer[tab[fd].cursor];
	else
	{
		read_size = read(fd, tab[fd].buffer, BUFFER_SIZE);
		if (read_size == 0 || read_size == -1)
			c = (char)read_size;
		else 
			c = tab[fd].buffer[0];
	}
	tab[fd].cursor++;
	if (c == 0 || tab[fd].cursor == BUFFER_SIZE)
		tab[fd].cursor = 0;
	return (c);
}


int		get_next_line(int fd, char **line)
{
	ssize_t line_size;
	ssize_t maxi_line;
	char	*tmp_line;
	char	c;

	line_size = 0;
	maxi_line = BUFFER_SIZE;
	if ((*line = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
		return (-1);
	while (((c = read_buffer(fd)) != '\n')  && (c > 0))
	{
		(*line)[line_size++] = c;
		if (line_size == maxi_line)
		{
			maxi_line += BUFFER_SIZE;
			tmp_line = *line;
			if ((*line = malloc(sizeof(char) * maxi_line + 1)) == NULL)
				return (-1);
			ft_strncpy(*line, tmp_line, line_size);
			free(tmp_line);
		}
	}
	(*line)[line_size] = '\0';
	if (c == 0 || c == -1)
		return (c);
	return (1);
}


int main(void)
{
	char *s;
	int fd = open("foobar", O_RDONLY);
	int df = open("barfoo", O_RDONLY);
	get_next_line(fd, &s);
	printf("==> |%s|\n", s);
	free(s);
	get_next_line(df, &s);
	printf("==> |%s|\n", s);
	free(s);
	get_next_line(fd, &s);
	printf("==> |%s|\n", s);
	free(s);
	get_next_line(df, &s);
	printf("==> |%s|\n", s);
	free(s);
	return (0);
}
