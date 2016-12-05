/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diesecheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:04:25 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/28 16:45:05 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int	ft_diesecheck(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			j++;
		i++;
		if ((buff[i] == '\n' && buff[i + 1] == '\n') || buff[i] == '\0')
		{
			if (j != 4)
				return (0);
			if (j == 4)
				j = 0;
		}
	}
	return (1);
}
