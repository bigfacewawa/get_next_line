/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 01:00:54 by yijhuang          #+#    #+#             */
/*   Updated: 2019/01/23 01:30:08 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nlstr(int fd, char **line, char *str[])
{
	char	buff[BUFF_SIZE + 1];
	char	*nlstr;
	char	*tmp;
	int		num;

	while ((num = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[num] = '\0';
		str[fd] = ft_strjoin_del(str[fd], buff, 1);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (num < 0)
		return (-1);
	tmp = str[fd];
	str[fd] = NULL;
	if ((nlstr = ft_strchr(tmp, '\n')))
		if (!(*nlstr = '\0'))
			str[fd] = ft_strdup(nlstr + 1);
	*line = ft_strdup(tmp);
	ft_strdel(&tmp);
	if (num == 0 && **line == 0 && !str[fd])
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static	char	*str[FD_SIZE];

	if (fd < 0 || line == NULL || fd > FD_SIZE || BUFF_SIZE <= 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	return (nlstr(fd, line, str));
}
