/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 09:00:39 by llelias           #+#    #+#             */
/*   Updated: 2019/01/15 18:51:51 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int		fd[argc];
	int		i;
	char	*line;

	i = argc - 1;
	if (argc < 2)
		return (-1);
	while (i > 0)
	{
		fd[i] = open(argv[i], O_RDONLY);
		i--;
	}
	while (i++ + 1 < argc)
	{
		while (get_next_line(fd[i], &line) > 0)
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}
		free(line);
	}
	return (0);
}
