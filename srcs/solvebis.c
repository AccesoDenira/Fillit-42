/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvebis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:53:48 by jegloff           #+#    #+#             */
/*   Updated: 2016/12/05 10:55:24 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

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

int	ft_checklastpoint(char **tab, char lettre, t_tab *lst[z], int size)
{
	/*fonction qui cherche le diese precedent celui que l on viens de placer
	 et verifie que leurs positions relatives sont bonnes*/
	int x;
	int	xtmp;
	int ytmp;
	int	y;

	x = 1;
	y = 1;
	while (tab[x][y])
	{
		while (x <= size)
		{
			if (tab[x][y] == lettre)
			{
				xtmp = (lst[z + 1]->x - lst[y]->x);
				ytmp = (lst[z + 1]->y - lst[y]->y);
				if (tab[x + xtmp][y + ytmp] == '.')
				{
					xtmp = (lst[z + 2]->x - lst[y]->x);
					ytmp = (lst[z + 2]->y - lst[y]->y);
					if (tab[x + xtmp][y + ytmp] == '.')
					{
						xtmp = (lst[z + 3]->x - lst[y]->x);
						ytmp = (lst[z + 3]->y - lst[y]->y);
						if (tab[x + xtmp][y + ytmp] == '.')
						{
							return (1);
							/*les quatres points sont placables*/
							/*on return 1 pour dire que la piece peux etre placee ici*/
						}
						else
							return (0);
					}
					else
						return (0);
				}
				else
					return (0);
			}
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}

char	**ft_ishashplacable(char **tab, t_tab *lst[z], char lettre, int size)
{
	/*fonction qui cherche a placer le # dans le tableau*/
	int xcount;
	int	xtmp;
	int	y;

	xtmp = 0;
	xcount = 0;
	y = 0;
	while (tab)
	{
		while (xcount < size)
		{
			if (tab[xtmp][y] == '.')
			{
				tab[xtmp][y] = lettre;
				return (tab);
			}
			xtmp++;
			xcount++;
		}
		xcount = 0;
		xtmp = x;
		y++;
	}
	/*Comment faire pour dire a ispieceplacable que le diese n a put etre place*/
	return (NULL);
}

int	ft_ispieceplacable(char **tab, t_tab *lst[z], lettre, size)
{
	/*fonction qui cherche a placer la z eme piece 
	dont les coordonnes sont contenues dans 4 maillons de la liste*/
	int	x;
	int y;
	int	xtmp;
	int	tmp;
	int	indice;

	i = 0;
	y = 0;
	xtmp = 0;
	ytmp = 0;
	indice = 1;
	if (ft_ishashplacable(tab, lst[z], lettre, size) && ft_checklaspoint(tab, lettre, lst[z, size]) == 1)
	{
		/*si conditions realisees la piece peut etre place pour cet emplacement de #*/
		/*il faut trouver le # place par ihashplacable*/
		while (tab)
		{
			if (tab[x][y] = lettre)
			{
				while (indice < 4)
				{
					xtmp = (lst[y + indice]->x - lst[y]->x);
					ytmp = (lst[y + indice]->y - lst[y]->y);
					tab[x + xtmp][y + ytmp] == lettre;
					indice++;
				}
			}
			x++;
			if (x == 3)
			{
				y++;
				x = 0;
			}
		}
	}
	return (tab)
}

static char	**ft_solve(t_tab *lst, int size)
{
	char **tab;
	int i;
	int j;
	int lettre;
	int z;

	i = 0;
	j = 0;
	z = 1
	lettre = 65;
/*malloc du tableau a deux dimensions de taille size * size*/
	char **tab = malloc(sizeof(*tab) * size);
	while (i++ < size)
		tab[i] = malloc(sizeof(**tab) * size);
	while (lst)
		if ((ft_ispieceplacable(lst[z], tab, lettre, size) == 1))
		{
			ft_ispieceplacable(lst[z + 4], tab, lettre + 1, size)
		}
		if ((ft_ispieceplacable(lst[z], tab, lettre, size) == 0) && z != 0)
			if (lst[z]->x < size)
				lst[z]->x = lst[z]->x + 1;
			else
				lst[z]->y = lst[z]->y + 1
			ft_ispieceplacable(lst[z], tab, lettre, size)
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
