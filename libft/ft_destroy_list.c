/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:02:19 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/18 20:05:54 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_destroy_list(t_list *p)
{
	t_list	*new;

	while (p != NULL)
	{
		new = p;
		p = p->next;
		free(new);
	}
}
