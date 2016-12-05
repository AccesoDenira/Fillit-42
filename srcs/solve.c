/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:05:27 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/03 13:45:17 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
#include <math.h>

double		ft_sqrt(int nb)
{
	int		i;
	double	a;
	double	n;
	double	hash;

	hash = nb * 4;
	i = 0;
	n = 1;
	a = 0;
	while (a < hash)
	{
		if (i > 46340 || nb >= 2147483647)
			return (0);
		a = a + n;
		n = n + 2;
		i++;
	}
	printf("%d\n", i);
	return (i);
}

int	ft_checklastpoint(char **tab, int numdiese, char lettre, t_tab *lst[y])
{
	/*fonction qui cherche le diese precedent celui que l on viens de placer
	 et verifie que leurs positions relatives sont bonnes*/
	int xcount;
	int	xtmp;
	int	lettrecount;
	int	y;

	xtmp = x;
	xcount = 0;
	lettrecount = 1;
	y = 0;
	while (tab)
	{
		while (xcount < min_size)
		{
			if (tab[xtmp][y] == lettre && lettrecount = numdiese)
			{
			/*On a trouve le # precedent celui que l on essaye de placer*/
			/*il faut trouver la difference qu il est sence y avoir entre les coordonnes du # precedent et celui que l on a place*/
			/*ex x1.y1 et x1.y2 , la difference doit etre y+1*/
			}
			if ((tab[xtmp][y] == lettre) && (lettrecount < numdiese))
			{
				lettrecount++;
			}
			xtmp++;
			xcount++;
		}
		xcount = 0;
		xtmp = x;
		y++
	}
}

char	**ft_ishashplacable(char **tab, int x, int y, int min_size, char lettre)
{
	/*fonction qui cherche a placer le # dans le tableau*/
	int xcount;
	int	xtmp;
	int	y;

	xtmp = x;
	xcount = 0;
	y = 0;
	while (tab[xtmp][y] != lettre)
	{
		while (xcount < min_size)
		{
			xtmp++;
			xcount++;
		}
		xcount = 0;
		xtmp = x;
		y++
	}
	while (tab)
	{
		while (xcount < min_size)
		{
			if (tab[xtmp][y] != '#')
				return (tab);
			xtmp++;
			xcount++;
		}
		xcount = 0;
		xtmp = x;
		y++;
	}
	return (tab);
}

int	ft_ispieceplacable(char **tab, t_tab *lst[y])
{
	/*fonction qui cherche a placer la y eme piece 
	dont les coordonnes sont contenues dans 4 maillons de la liste*/
	int	i;

	i = 1;
	while (i <= 4)
	{
		/* Recuperer x et y du i eme # de la piece */
		if (ft_ishashplacable(tab, x, y, min_size, lettre) == 1 && ft_checklaspoint(tab, numdiese, lettre) == 1)
			/*si conditions realisees le diese est bien place, on essaye de placer le diese suivant (pour un max de 4fois)*/
			i++;
		return (0);
	}
	return (1);
}

static char	**ft_solve(t_tab *lst, int size)
{
	char **tab;
	int i;

	i = 0;
	/*malloc du tableau a deux dimensions de taille size * size*/
	while (lst)
		if ((ft_ispieceplacable(lst[i], tab) == 1))
		{
			ft_ispieceplacable(lst[i++], tab)
		}
		if ((ft_ispieceplacable(lst[i], tab) == 0) && i != 0)
			if (tab[i]->x <= size)
				x = x + 1;
			else
				y = y + 1
			ft_ispieceplacable(lst[i--], tab)
	return (tab);
}

int	main(void)
{
	int	i;
	int	size;

	i = 3;
	size = 0;
	size = ft_sqrt(i);
	ft_solve(size, lst)
	return (0);
}