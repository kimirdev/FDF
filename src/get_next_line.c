/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <gyellowj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:13:08 by gyellowj          #+#    #+#             */
/*   Updated: 2019/10/21 17:41:18 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list				*ft_find_fd(int fd, t_list **elem)
{
	t_list			*tmp;

	if (!elem)
		return (NULL);
	tmp = *elem;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(elem, tmp);
	tmp = *elem;
	return (tmp);
}

int					ft_free_list(t_list **elem, t_list **file)
{
	t_list			*q;

	q = *elem;
	if (q->content_size == (*file)->content_size)
		(*elem) = (*elem)->next;
	else
	{
		while (q->next->content_size != (*file)->content_size)
			q = q->next;
		q->next = (*file)->next;
	}
	free((*file)->content);
	free(*file);
	return (0);
}

void				*ft_split(char *tmp, char **line, char **content)
{
	int				i;

	i = 0;
	while ((*content)[i] != '\n' && (*content)[i] != '\0')
		i++;
	if (!((*line) = ft_strsub(*content, 0, i)))
		return (NULL);
	if ((*content)[i] == '\0')
	{
		free(*content);
		return (NULL);
	}
	if (!(tmp = ft_strdup(&(*content)[i + 1])))
		return (NULL);
	free(*content);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*elem;
	t_list			*file;
	char			*tmp;
	int				wr;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	file = ft_find_fd(fd, &elem);
	while ((wr = read(fd, buf, BUFF_SIZE)))
	{
		buf[wr] = '\0';
		tmp = ft_strjoin(file->content, buf);
		free(file->content);
		file->content = tmp;
		if (ft_strchr(file->content, '\n'))
			break ;
	}
	if (!(file->content) || !ft_strlen(file->content))
		return (ft_free_list(&elem, &file));
	file->content = ft_split(tmp, line, (char **)&file->content);
	return (1);
}
