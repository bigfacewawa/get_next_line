/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 23:15:10 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/19 10:51:55 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	end;
	int	i;

	i = 0;
	end = (int)ft_strlen(s1);
	while (*(s2 + i))
	{
		*(s1 + end + i) = *(s2 + i);
		i++;
	}
	*(s1 + end + i) = '\0';
	return (s1);
}
