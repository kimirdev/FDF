/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:16:03 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/17 21:35:52 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned char	*str;

	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return ((char*)str);
}
