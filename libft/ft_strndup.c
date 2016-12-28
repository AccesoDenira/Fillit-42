/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:24:34 by thgiraud          #+#    #+#             */
/*   Updated: 2016/11/26 15:25:00 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *dst;

	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	dst = ft_strncpy(dst, s1, n);
	dst[n] = '\0';
	return (dst);
}
