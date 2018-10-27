/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 03:26:17 by tmarchen          #+#    #+#             */
/*   Updated: 2018/01/02 03:26:20 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}						t_gnl;

# define BUFF_SIZE 6000

int						get_next_line(const int fd, char **line);

#endif
