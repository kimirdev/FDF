/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:38 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/12 20:56:08 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if (ch == '\0')
		return ((void *)str + ft_strlen((char *)str));
	while (*str)
	{
		if (*str == (char)ch)
			return ((char*)str);
		str++;
	}
	return (0);
}
