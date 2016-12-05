/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:49:34 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/04 13:01:18 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
#include <unistd.h>

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

char		*ft_check_n_left(char *str)
{
	char	*tmp;

	tmp = str;
	if (ft_verif(str) != 1)
		ft_error();
	if (ft_diesecheck(str) != 1)
		ft_error();
	tmp = ft_top_side(str);
	tmp = ft_left_side(str);
	return (tmp);
}

t_tab		*ft_storage(char *str)
{
	int		j;
	char	c;
	t_tab	*tab;
	t_tab	*tmp;

	j = 0; 
	c = 65;
	if (!(tab = (t_tab *)malloc(sizeof(t_tab))))
		return (NULL);
	tmp = tab;
	str = ft_check_n_left(str);
	while (str[j])
	{
		tmp->str = ft_strndup(&str[j], 20);
		if (ft_piececheck(tmp->str) == 0)
			ft_error();
		tmp->c = c;
		j = j + 19;
		if (str[j + 1] == '\n')
		{
			j++;
			j++;
		}
		if (!(tmp->next = (t_tab *)malloc(sizeof(t_tab))))
			return (NULL);
		tmp = tmp->next;
		tmp->next = NULL;
		c++;
	}
	tmp->next = NULL;
	return (tab);
}

char		*ft_read(char *file)
{
	int		fd;
	int		stat;
	int		i;
	char	tmp[545];
	char	buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((stat = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
			if (i > 545)
				ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

int			main(int ac, char **av)
{
	t_tab	*tab;
	char	*reader;
	char	**res;

	if (ac != 2)
		ft_error();
	reader = ft_read(av[1]);
	tab = ft_storage(reader);
	tab = ft_default_xy(tab);
	return (0);
}
