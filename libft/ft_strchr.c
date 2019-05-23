/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:54:16 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/29 22:56:34 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char*)s;
	i = 0;
	if ((char)c == '\0')
	{
		while (*(ptr + i) != '\0')
			i++;
		return (ptr + i);
	}
	else
	{
		while (*(ptr + i))
		{
			if (*(ptr + i) == (char)c)
			{
				return (ptr + i);
			}
			i++;
		}
	}
	return (NULL);
}
