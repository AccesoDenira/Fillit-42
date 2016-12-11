/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:23:25 by jegloff           #+#    #+#             */
/*   Updated: 2016/12/10 16:16:36 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	ft_getc(t_tab *lst, int i)
{
	int j;

	j = 0;
	if (lst == NULL)
		ft_error();
	while (lst->next)
	{
		if (j == i)
			return (lst->c);
		j++;
		lst = lst->next;
	}
	return (lst->c);
}

int	ft_getx(t_tab *lst, int i, int y)
{
	int j;

	j = 0;
	if (lst == NULL)
		ft_error();
	while (lst)
	{
		if (j == i)
			return (lst->x[y]);
		j++;
		lst = lst->next;
	}
	return (0);
}

int	ft_gety(t_tab *lst, int i, int y)
{
	int j;

	j = 0;
	if (lst == NULL)
		ft_error();
	while (lst->next)
	{
		if (j == i)
			return (lst->y[y]);
		j++;
		lst = lst->next;
	}
	return (0);
}

int	ft_getdecalx(t_tab *lst, int i)
{
	int j;

	j = 0;
	if (lst == NULL)
		ft_error();
	while (lst->next)
	{
		if (j == i)
			return (lst->decalx);
		j++;
		lst = lst->next;
	}
	return (0);
}

int	ft_getdecaly(t_tab *lst, int i)
{
	int j;

	j = 0;
	if (lst == NULL)
		ft_error();
	while (lst->next)
	{
		if (j == i)
			return (lst->decaly);
		j++;
		lst = lst->next;
	}
	return (0);
}

void	ft_printab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
