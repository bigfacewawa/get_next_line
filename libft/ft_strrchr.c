/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:00:55 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/16 20:00:42 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = (int)ft_strlen(s) + 1;
	ptr = (char*)s;
	while (i--)
	{
		if (*(ptr + i) == (char)c)
		{
			return (ptr + i);
		}
	}
	return (NULL);
}
