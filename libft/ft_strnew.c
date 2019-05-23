/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:52:06 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/29 23:07:51 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char*)malloc(size + 1);
	if (ptr)
	{
		while (i < (size + 1))
		{
			*(ptr + i) = '\0';
			i++;
		}
		return (ptr);
	}
	else
	{
		return (NULL);
	}
}
