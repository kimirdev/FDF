/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:23:52 by gyellowj          #+#    #+#             */
/*   Updated: 2019/09/17 22:05:23 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_word(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

int			ft_word(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	if (!s || !(arr = (char**)malloc(sizeof(char*) *
			(ft_count_word(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(arr[i] = (char*)malloc(sizeof(char) * (ft_word(s, c) + 1))))
				return (NULL);
			j = 0;
			while (*s != c && *s)
				arr[i][j++] = *(s++);
			arr[i][j] = '\0';
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
