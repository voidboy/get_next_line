/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclerac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:00:22 by aclerac           #+#    #+#             */
/*   Updated: 2021/01/25 16:33:08 by aclerac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_LIMIT 0x100
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_library {
	char			buffer[BUFFER_SIZE];
	unsigned int	cursor;
}				t_library;

int				get_next_line(int fd, char **line);
char			*ft_strncpy(char *dest, const char *src, size_t n);
#endif
