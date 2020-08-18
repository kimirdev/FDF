/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:50:55 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/12 19:50:23 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while (((*str > 8) && (*str < 14)) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		if (i <= 9223372036854775807)
			i = (i * 10) + (*str - '0');
		else if (sign == -1)
			return (0);
		else
			return (-1);
		str++;
	}
	return (i * sign);
}
