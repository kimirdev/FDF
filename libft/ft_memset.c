/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:52:15 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/09 21:04:27 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*new_ptr;
	size_t			i;

	i = 0;
	new_ptr = (unsigned char*)ptr;
	while (i < num)
	{
		new_ptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
