/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piececheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:37:04 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/28 19:00:24 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int	ft_firstcheck(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
		{
			if (buff[i + 4] == '#')
				return (1);
			if (buff[i + 2] == '#')
				return (1);
			if (buff[i + 10] == '#')
				return (1);
			if (buff[i + 6] == '#')
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_secondcheck(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
		{
			if (buff[i + 6] == '#')
			{
				if ((buff[i + 7] == '#') || (buff[i + 11] == '#'))
					return (1);
			}
			if (buff[i + 2] == '#')
			{
				if ((buff[i + 3] == '#') || (buff[i + 7] == '#'))
					return (1);
			}
			if ((buff[i + 2] == '#') && (buff[i + 6] == '#'))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_thirdcheck(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
		{
			if (buff[i + 6] == '#')
				if ((buff[i + 7] == '#') || (buff[i + 11] == '#'))
					return (1);
			if (buff[i + 4] == '#')
				if ((buff[i + 3] == '#') || (buff[i + 9] == '#'))
					return (1);
			if (buff[i + 10] == '#')
			{
				if ((buff[i + 9] == '#') || (buff[i + 11] == '#'))
					return (1);
				if (buff[i + 15] == '#')
					return (1);
			}
			if ((buff[i + 6] == '#') && (buff[i + 10] == '#'))
				return (1);
			if ((buff[i + 6] == '#') && (buff[i + 4] == '#'))
				return (1);
			if ((buff[i + 4] == '#') && (buff[i + 10] == '#'))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_piececheck(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
		{
			if ((buff[i + 1] == '#') && (buff[i + 5] == '#'))
				if (ft_firstcheck(buff) == 1)
					return (1);
			if ((buff[i + 1] == '#') && (buff[i + 5] != '#'))
				if (ft_secondcheck(buff) == 1)
					return (1);
			if ((buff[i + 1] != '#') && (buff[i + 5] == '#'))
				if (ft_thirdcheck(buff) == 1)
					return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

