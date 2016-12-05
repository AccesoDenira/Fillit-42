/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:53:13 by thgiraud          #+#    #+#             */
/*   Updated: 2016/12/04 12:59:19 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_modify_top(char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			buff[i] = '.';
			buff[i - 5] = '#';
		}
		i++;
	}
	return (buff);
}

char	*ft_modify_left(char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			buff[i] = '.';
			buff[i - 1] = '#';
		}
		i++;
	}
	return (buff);
}

char	*ft_top_side(char *buff)
{
	int		i;
	int		d;
	int		p;

	i = 0;
	d = 0;
	p = 0;
	while (buff[i++])
	{
		d = 0;
		p = 0;
		if (buff[i] == '.')
			p++;
		else if (buff[i] == '#')
			d++;
		if (buff[i] == '\n' && p == 4 && i < 15)
		{
			buff = ft_modify_top(buff);
			i = 0;
		}
	}
	return (buff);
}

char	*ft_left_side(char *buff)
{
	int		i;
	int		j;
	int		d;
	int		p;

	i = 0;
	j = 0;
	d = 0;
	p = 0;
	while (buff[j + 5])
	{
		if (buff[j] == '.')
			p++;
		else if (buff[j] == '#')
			d++;
		if (p == 4 && i != 4)
		{
			buff = ft_modify_left(buff);
			p = 0;
			d = 0;
			j = 0;
		}
	}
}
