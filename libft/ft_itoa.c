/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:12:45 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/17 17:35:14 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_len(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i = 1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[0] = '0';
	str[i] = '\0';
	while (n > 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
