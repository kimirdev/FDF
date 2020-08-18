/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:59:44 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/12 15:00:32 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *ptr, size_t num)
{
	unsigned char	*new_ptr;

	new_ptr = (unsigned char*)ptr;
	while (num--)
		new_ptr[num] = '\0';
}
