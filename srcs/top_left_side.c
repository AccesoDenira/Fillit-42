/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:53:13 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/05 11:50:05 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_modify_top(char *buff, int d)
{
	int		i;
	int		j;

	i = d * 20 + d;
	j = i;
	while (buff[i] && i <= (j + 18))
	{
		if (buff[i] == '#')
		{
			buff[i] = '.';
			buff[i - 5] = '#';
		}
		i++;
	}
	return (buff);
}

char	*ft_modify_left(char *buff, int d)
{
	int		i;
	int		j;

	i = d * 20 + d;
	j = i;
	while (buff[i] && i <= (j + 18))
	{
		if (buff[i] == '#')
		{
			buff[i] = '.';
			buff[i - 1] = '#';
		}
		i++;
	}
	return (buff);
}

char	*ft_top_side(char *buff)
{
	int		i;
	int		d;
	int		p;
	int		diese;

	i = -1;
	d = 0;
	p = 0;
	diese = 0;
	while (buff[++i])
	{
		if (buff[i] == '.')
		{
			p++;
		}
		if (buff[i] == '#')
			diese++;
		if (buff[i] == '\n' && p == 4 && i < (15 + 20 * d) && diese == 0)
		{
			buff = ft_modify_top(buff, d);
			p = 0;
			i = -1 + d + (d * 20);
		}
		if (buff[i] == '\n')
		{
			p = 0;
		}
		if (buff[i] == '\n' && buff[i + 1] == '\n')
		{
			d++;
			diese = 0;
		}
	}
	return (buff);
}

char	*ft_left_side(char *buff)
{
	int		i;
	int		d;
	int		p;
	int		ligne;

	i = 0;
	d = 0;
	p = 0;
	ligne = 1;
	while (buff[i])
	{
		if (buff[i] == '.')
			p++;
		if (ligne == 4)
		{
			if (p == 4)
			{
				ft_modify_left(buff, d);
				i = 0 + (d * 21) - 5;
				p = 0;
				ligne = 0;
			}
		}
		if (buff[i] == '\n' && buff[i - 1] == '\n')
		{
			d++;
			i = i + 1 - 5;
			p = 0;
			ligne = 0;
		}
		ligne++;
		i = i + 5;
	}
	return (buff);
}
