/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclerac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:05:59 by aclerac           #+#    #+#             */
/*   Updated: 2021/01/25 14:41:37 by aclerac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] && n)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (n)
		while (n--)
			dest[i++] = '\0';
	return (dest);
}
