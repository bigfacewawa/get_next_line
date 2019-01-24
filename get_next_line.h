/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:39:28 by yijhuang          #+#    #+#             */
/*   Updated: 2019/01/12 21:48:37 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
* protect .h file
*/

# define BUFF_SIZE 42
# define FD_SIZE 4862

# include "libft/libft.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
/*
* for read() use
*/
# include <stdlib.h>
/*
* for malloc()&free() use
*/
# include <fcntl.h>
/*
* for open() use
*/


int		get_next_line(const int fd, char **line);

#endif
