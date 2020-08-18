/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:19:28 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/18 16:24:53 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	strlendst;
	size_t	strlensrc;
	size_t	run;

	strlendst = ft_strlen(dst);
	strlensrc = ft_strlen(src);
	if (size == 0)
		return (strlensrc);
	if (size - 1 < strlendst)
		return (strlensrc + size);
	run = 0;
	while ((strlendst + run < size - 1) && src[run])
	{
		dst[strlendst + run] = src[run];
		run++;
	}
	dst[strlendst + run] = '\0';
	return (strlendst + strlensrc);
}
