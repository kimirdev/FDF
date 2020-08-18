/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:12:22 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/15 17:25:11 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int		i;
	size_t	l;

	l = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (*s1 && l < len)
	{
		if (*s1 == s2[i])
			i++;
		else
		{
			s1 = s1 - i;
			i = 0;
		}
		if (s2[i] == '\0')
			return ((char*)(s1 - i + 1));
		l++;
		s1++;
	}
	return (NULL);
}
