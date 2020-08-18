/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:06 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/17 17:35:14 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t count)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	if (!dest && !src && count)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	if (s < d)
		while ((int)(--count) >= 0)
			*(d + count) = *(s + count);
	else
		while (++i < count)
			*(d + i) = *(s + i);
	return (dest);
}
