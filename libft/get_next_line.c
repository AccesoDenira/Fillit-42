/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:06:42 by mdamette          #+#    #+#             */
/*   Updated: 2016/11/23 10:35:24 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	get_line(t_line *tline, char **line)
{
	char	*next;

	if (!ft_strlen(tline->str))
		return (0);
	if (!tline->newline)
	{
		*line = tline->str;
		tline->str = ft_strnew(0);
		return (1);
	}
	next = ft_strchr(tline->str, '\n');
	*next++ = '\0';
	*line = ft_strdup(tline->str);
	ft_strcpy(tline->str, next);
	tline->newline--;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char				*buff;
	char				*tmp;
	int					ret;
	static t_line		tline;

	if (tline.str == NULL)
		tline.str = ft_strnew(0);
	while (!tline.newline)
	{
		buff = ft_strnew(BUFF_SIZE);
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (get_line(&tline, line));
		tline.newline = ft_countchar(buff, '\n');
		tmp = ft_strjoin(tline.str, buff);
		free(tline.str);
		tline.str = tmp;
		free(buff);
	}
	return (get_line(&tline, line));
}
