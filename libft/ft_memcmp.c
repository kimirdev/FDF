/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:15:29 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/15 20:16:27 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	j = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (j < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
		j++;
	}
	return (0);
}
