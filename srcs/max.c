/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:08:33 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/05 11:01:47 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fillit.h>

char	**ft_empty(char **tab, int max)
{
	int		y;
	int		x;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		tab[y] = ft_strnew(max)
		x = 0;
		while (x < max)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

int		ft_max(t_tab *tab)
{
	int		i;
	int		max;

	i = 0;
	max = 2;
	while (tab->next && i++)
		tab= tab->next;
	while (max * max < i * 4)
		max++;
	return (max);
}
