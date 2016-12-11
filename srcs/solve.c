/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:57:09 by jegloff           #+#    #+#             */
/*   Updated: 2016/12/11 13:59:47 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

static char		**ft_reset(char **t, t_tab *tab, int max, int i)
{
	int		x;
	int		y;

	y = 0;
	printf("%s\n", "Je bouge dans ft_reset");
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (t[y][x] == ft_getc(tab, i))
				t[y][x] = '.';
			x++;
		}
		y++; 
	}
	return (t);
}

static char		**ft_saved(char **t, t_tab *lst, int size, int i)
{
	int		x;
	int		y;

	y = 0;
	printf("%s\n", "wesh je bouge dans ft_saved");
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (t[x][y] == '#')
			{
				printf("%s\n", "on a trouve le diese");
				ft_printab(t, size);
				t[x][y] = '.';
				ft_printab(t, size);
				t[x + ft_getx(lst, i, 0)][y + ft_gety(lst, i, 0)] = ft_getc(lst, i);
				ft_printab(t, size);
				t[x + ft_getx(lst, i, 1)][y + ft_gety(lst, i, 1)] = ft_getc(lst, i);
				ft_printab(t, size);
				t[x + ft_getx(lst, i, 2)][y + ft_gety(lst, i, 2)] = ft_getc(lst, i);
				ft_printab(t, size);
				t[x + ft_getx(lst, i, 3)][y + ft_gety(lst, i, 3)] = ft_getc(lst, i);
				ft_printab(t, size);
			}
			x++;
		}
		y++;
	}
	printf("%s\n", "apres saved :");
	ft_printab(t, size);
	return (t);
}

char	**ft_check(char **t, t_tab *lst, int size, int i)
{
	int	xt;
	int	yt;
	int	xlist;
	int	ylist;
	int once;

	printf("%s\n", "salut je rentre dans ft_check");
	yt = ft_getdecaly(lst, i);
	xlist = ft_getx(lst, i, 0);
	ylist = ft_gety(lst, i , 0);
	once = 0;
	while (yt < size)
	{
		xt = 0;
		if (once++ == 0)
			xt = ft_getdecalx(lst,i);
		while (xt < size)
		{
			if (t[xt + xlist][yt + ylist] == '.')
			{
				xlist = ft_getx(lst, i, 1);
				ylist = ft_gety(lst, i, 1);
				if (t[xt + xlist][yt + ylist] == '.')
				{
					xlist = ft_getx(lst, i, 2);
					ylist = ft_gety(lst, i, 2);
					if (t[xt + xlist][yt + ylist] == '.')
					{
						xlist = ft_getx(lst, i, 3);
						ylist = ft_gety(lst, i, 3);
						if (t[xt + xlist][yt + ylist] == '.')
						{
							t[xt][yt] = '#';
							ft_printab(t, size);
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

char		**ft_solve(char **t, t_tab *lst, int size, int i)
{
	int	j;

	j = 0;
	while (i < 3)
	{
		printf("%s\n", "salut je rentre dans le while de solve");
		if (ft_check(t, lst, size, i) != NULL)
		{
			ft_saved(t, lst, size, i);
			i++;
			ft_solve(t, lst, size, i);
		}
		if (ft_check(t, lst, size, i ) == NULL)
		{
			if (i == 0)
			{
				size++;
				ft_result(lst, size);
			}
			i--;
			ft_reset(t, lst, size, i);
			if (ft_getdecalx(lst, i) < size)
				lst->decalx++;
			else if (ft_getdecaly(lst, i) == size)
			{
				lst->decaly++;
				lst->decalx = 0;
			}
			ft_solve(t, lst, size, i);
		}
		ft_checkos(t, lst, size);
	}
	return (t);
}

char			**ft_result(t_tab *lst, int size)
{
	char	**t;

	t = NULL;
	t = ft_empty(t, size);
	/*printf("%s\n", "piece 1");
	printf("getx0 = %d\n", ft_getx(lst, 0, 0));
	printf("gety0 = %d\n", ft_gety(lst, 0, 0));
	printf("getx1 = %d\n", ft_getx(lst, 0, 1));
	printf("gety1 = %d\n", ft_gety(lst, 0, 1));
	printf("getx2 = %d\n", ft_getx(lst, 0, 2));
	printf("gety2 = %d\n", ft_gety(lst, 0, 2));
	printf("getx3 = %d\n", ft_getx(lst, 0, 3));
	printf("gety3 = %d\n", ft_gety(lst, 0, 3));
	printf("c = %c\n", ft_getc(lst, 0));
	printf("%s\n", "piece 2");
	printf("getx0 = %d\n", ft_getx(lst, 1, 0));
	printf("gety0 = %d\n", ft_gety(lst, 1, 0));
	printf("getx1 = %d\n", ft_getx(lst, 1, 1));
	printf("gety1 = %d\n", ft_gety(lst, 1, 1));
	printf("getx2 = %d\n", ft_getx(lst, 1, 2));
	printf("gety2 = %d\n", ft_gety(lst, 1, 2));
	printf("getx3 = %d\n", ft_getx(lst, 1, 3));
	printf("gety3 = %d\n", ft_gety(lst, 1, 3));
	printf("c = %c\n", ft_getc(lst, 1));*/
	t = ft_solve(t, lst, size, 0);
	return (t);
}
