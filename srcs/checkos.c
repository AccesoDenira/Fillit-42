/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:41:54 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/11 14:10:21 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_checkos(char **t, t_tab *lst, int max)
{
	int		x;
	int		y;
	int		c;

	y = 0;
	while (lst->next)
		lst = lst->next;
	while (x < max)
	{
		x = 0;
		while (y < max)
		{
			if (t[x][y] == lst->c)
				return (t);
		}
	}
	return (0);
}
