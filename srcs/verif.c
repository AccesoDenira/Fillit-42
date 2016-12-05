/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:12:42 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/28 19:00:53 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int	ft_linereturn(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			if (buff[i + 1] == '\n' && buff[i + 2] == '\n')
				return (0);
		if (buff[i] == '#' || buff[i] == '.')
			if (buff[i + 1] == '\0')
				return (1);
		i++;
	}
	return (0);
}

int	ft_goodcontent(char *buff)
{ 
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '.' || buff[i] == '#' || buff[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_goodlinesize(char **tab)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
			j++;
		if (j != 4)
		{
			return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_goodsquare(char *buff)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if (buff[i + 1] == '\n' || buff[i + 1] == '\0')
			{
				if (j != 20)
				{
					return (0);
				}
				j = -1;
			}
		}
		i++;
		j++;
	}
	return (1);
}

int	ft_verif(char *buff)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(buff, '\n');
	if (ft_goodlinesize(tab) == 0)
		return (0);
	if (ft_linereturn(buff) == 0)
		return (0);
	if (ft_goodcontent(buff) == 0)
		return (0);
	if (ft_goodsquare(buff) == 0)
		return (0);
	return (1);
}

