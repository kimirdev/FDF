/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:44:55 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/12 17:06:21 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (!dest && !src && count)
		return (NULL);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
