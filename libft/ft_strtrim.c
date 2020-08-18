/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:37:32 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/18 14:34:24 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strsub(s, i, 1));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(str = ft_strsub(s, i, j - i + 1)))
		return (NULL);
	return (str);
}
