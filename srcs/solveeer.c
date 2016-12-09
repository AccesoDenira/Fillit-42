/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:22:54 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/09 15:19:44 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

static char		**ft_reset(char **t, t_tab *tab, int max, int i)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (t[y][x] == tab[i]->c)
				t[y][x] = '.';
			x++;
		}
		y++;
	}
	return (t);
}

static char		**ft_saved(char **t, t_tab *lst, int max, int i)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (t[x][y] == '#')
			{
				t[x][y] == '.';
				t[x + lst->x[i]][y + lst->y[i]] = lst->c[i];
				t[x + lst->x[i + 1]][y + lst->y[i + 1]] = lst->c[i];
				t[x + lst->x[i + 2]][y + lst->y[i + 2]] = lst->c[i];
				t[x + lst->x[i + 3]][y + lst->y[i + 3]] = lst->c[i];
			}
			x++;
		}
		y++;
	}
	return (t);
}

char	**ft_check(char **t, t_tab *lst, int max, int i)
{
	int	xt;
	int	yt;
	int	xlist;
	int	ylist;
	int once;

	yt = lst->decaly[i];
	xlist = lst->x[i];
	ylist = lst->y[i];
	once = 0;
	while (yt < max)
	{
		xt = 0;
		if (once++ = 0)
			xt = lst->decaly[i];
		while (xt < max)
		{
			if (t[xt + xlist][yt + ylist] == '.')
			{
				i++;
				xlist = lst->x[i];
				ylist = lst->y[i];
				if (t[xt + xlist][yt + ylist] == '.')
				{
					i++;
					xlist = lst->x[i];
					ylist = lst->y[i];
					if (t[xt + xlist][yt + ylist] == '.')
					{
						i++;
						xlist = lst->x[i];
						ylist = lst->y[i];
						if ((t[xt + xlist][yt + ylist] == '.'))
						{
							t[xt][yt] == '#';
							return (t);
						}
					}
				}
			}
			xt++;
		}
		yt++;
	}
	return (NULL);
}

char		**ft_solve(char **t, t_tab *lst, int max, int i)
{
	int		j;

	while (lst->next)
	{
		if (ft_check(t, lst, max, i) != NULL)
		{
			ft_saved(t, lst, max, i);
			i = 1 + 4;
			ft_solve(t, lst, max, i);
		}
		else if (ft_check(t, lst, max, i) == NULL)
		{
			if (i == 0)
			{
				max++;
				ft_result(lst, max);
			}
			i = i - 4;
			ft_reset(t, lst, max, i)
			if (lst->decalx[i] < max)
				lst->decalx[i] = lst->decalx[i] + 1;
			else
			{
				lst->decaly[i] = lst->decaly[i] + 1;
				lst->decaly[i] = 0;
			}
			ft_solve(t, lst, max, i);
		}
	}
	return (t);
}

char		**ft_result(t_tab *lst, int max)
{
	char	**t;

	t = NULL;
	while (*t[max])
	{	
		t = ft_empty(t, max);
		t = ft_solve(t, lst, max);
		max++;
	}
	return (t)
}
