/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoutik <abdelkarimoutik@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:33:53 by amoutik           #+#    #+#             */
/*   Updated: 2018/10/15 09:31:24 by amoutik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		buffer_line(char **line, char **file)
{
	char	*tmp;
	int		i;

	i = 0;
	if (**file == '\0')
		return (0);
	while ((*file)[i] && (*file)[i] != '\n')
		i++;
	if (ft_strlen(*file) == 0)
		return (0);
	tmp = ft_strsub(*file, 0, i);
	*file = *file + i + 1;
	*line = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*current[256];

	ret = 0;
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if ((current[fd] == NULL) && (current[fd] = ft_strnew(1)) == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		current[fd] = ft_strjoin(current[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return ((buffer_line(line, &current[fd])) ? 1 : 0);
}
