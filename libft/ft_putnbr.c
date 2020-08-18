/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:11:49 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/17 20:33:25 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
		return ;
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	if (n >= 0)
		ft_putchar((n % 10) + '0');
}
