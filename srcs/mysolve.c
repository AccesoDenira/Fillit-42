/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:56:17 by mdamette          #+#    #+#             */
/*   Updated: 2016/12/05 11:01:41 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char		**ft_reset(char **t, t_tab *tab, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (t[y][x] == tab->c)
				t[y][x] = '.';
			x++;
		}
		y++;
	}
	return (t);
}

static char		**ft_saved(char **t, t_tab *tab, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab->x[i] == x && tab->y[i] == y)
			{
				t[y][x] = tab->c;
				i++;
			}
			x++;
		}
		t[y][x] = '\0';
		y++;
	}
	t[y] = NULL;
	return (t);
}

static int		ft_check(char **t, t_tab *tab, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab->x[i] == x && tab->y[i] == y && t[y][x] != '.')
				return (0);
			else if (tab->x[i] == x && tab->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char		**ft_solve(char **t, t_tab *tab, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!tab->next)
		return (t);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			tab = ft_update_xy(tab, x, y);
			if (ft_check(t, tab, max))
				tmp = ft_solve(ft_saved(t, tab, max), tab->next, max);
			if (tmp)
				return (tmp);
			t = ft_reset(t, tab, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char			**ft_result(t_tab *tab, int max)
{
	char	**t;

	t = NULL;
	while (!t)
	{
		t = ft_fill_empty(t, max);
		t = ft_solve(t, tab, max);
		max++;
	return (t);
}
