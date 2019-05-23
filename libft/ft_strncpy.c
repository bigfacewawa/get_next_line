/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:44:27 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/29 23:06:16 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*(src + i))
		{
			*(dst + i) = *(src + i);
		}
		else
		{
			while (i < len)
			{
				*(dst + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (dst);
}
