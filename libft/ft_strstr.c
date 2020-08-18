/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:58:11 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/17 17:35:14 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (*s1)
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
		s1++;
	}
	return (NULL);
}
