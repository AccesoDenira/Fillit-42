/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:28:40 by thgiraud          #+#    #+#             */
/*   Updated: 2016/11/24 18:31:08 by thgiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_tab
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_tab	*next;
}					t_tab

#endif
