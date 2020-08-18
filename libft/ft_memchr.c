/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:03:35 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/18 16:44:59 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *str, int ch, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char*)str;
	while (i < n)
	{
		if (*s == (char)ch)
			return (s);
		s++;
		i++;
	}
	return (NULL);
}
