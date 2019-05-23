/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:04:18 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/29 22:52:03 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *ret;

	ret = dst;
	if (dst <= src || dst >= src + len)
	{
		while (len--)
		{
			*(char*)dst = *(char*)src;
			dst = dst + 1;
			src = src + 1;
		}
	}
	else
	{
		dst = dst + len - 1;
		src = src + len - 1;
		while (len--)
		{
			*(char*)dst = *(char*)src;
			dst = dst - 1;
			src = src - 1;
		}
	}
	return (ret);
}
