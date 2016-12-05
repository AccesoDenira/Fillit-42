/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:05:53 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/03 15:47:15 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_tab	*ft_tab_xy(t_tab *tab, char **str)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{	
			if (str[y][x] == '#')
			{
				tab->x[i] = x;
				tab->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tab);
}

t_tab			*ft_default_xy(t_tab *tab)
{
	t_tab	*tmp;

	tmp = tab;
	while (tab->next)
	{
		tab = ft_tab_xy(tab, ft_strsplit(tab->str, '\n'));
		free(tab->str);
		tab = tab->next;
	}
	return (tmp);
}
