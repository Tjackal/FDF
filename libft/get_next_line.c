/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 21:27:18 by tmarchen          #+#    #+#             */
/*   Updated: 2017/12/30 21:27:20 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		write_line(char **line, char *buff, int i)
{
	int		j[2];
	char	*tmp;

	if (*line && (j[0] = -1))
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(*line) + i + 1))))
			return (-1);
		while ((*line)[++j[0]])
			tmp[j[0]] = (*line)[j[0]];
		j[1] = -1;
		while (++j[1] < i)
			tmp[j[0]++] = buff[j[1]];
		tmp[j[0]] = 0;
		free(*line);
		*line = tmp;
	}
	else if ((j[0] = -1))
	{
		if (!(*line = (char*)malloc(sizeof(char) * (i + 1))))
			return (-1);
		while (++j[0] < BUFF_SIZE && buff[j[0]] != '\n' && buff[j[0]])
			(*line)[j[0]] = buff[j[0]];
		(*line)[j[0]] = 0;
	}
	return (1);
}

int		refresh_rest(t_gnl *rest, int i)
{
	int		j;
	char	*tmp;

	tmp = rest->str;
	j = ft_strlen(rest->str) - i;
	if (!(rest->str = (char*)malloc(sizeof(char) * (j + 1))))
		return (-1);
	j = 0;
	while (tmp[++i])
		rest->str[j++] = tmp[i];
	free(tmp);
	rest->str[j] = 0;
	return (1);
}

int		check_rest(t_gnl *rest, int fd, char **line)
{
	int		i;
	int		j;

	j = 0;
	while (rest)
	{
		if (rest->fd == fd && ft_strlen(rest->str))
		{
			i = -1;
			while (rest->str[++i] && rest->str[i] != '\n')
				j++;
			if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
				return (-1);
			i = -1;
			while (rest->str[++i] && rest->str[i] != '\n')
				(*line)[i] = rest->str[i];
			(*line)[i] = 0;
			if (rest->str[i] == '\n')
				return (refresh_rest(rest, i));
			free(rest->str);
			rest->fd = -1;
		}
		rest = rest->next;
	}
	return (0);
}

int		nu_rst(t_gnl **rest, int fd, int i, char *buff)
{
	t_gnl	*t;
	int		j;

	j = -1;
	t = (t_gnl*)malloc(sizeof(t_gnl));
	if (!(t->str = (char*)malloc(sizeof(char) * (BUFF_SIZE - i + 1))))
		return (-1);
	t->fd = fd;
	while (++i < BUFF_SIZE)
		t->str[++j] = buff[i];
	t->str[++j] = 0;
	t->next = *rest;
	*rest = t;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				j;
	char			buff[BUFF_SIZE];
	static t_gnl	*rest;

	if (fd < 0 || BUFF_SIZE < 1 || !line || (*line = NULL))
		return (-1);
	if ((i = check_rest(rest, fd, line)) == 1)
		return (1);
	else if (i == -1)
		return (-1);
	while (ft_memset(buff, 0, BUFF_SIZE) && (j = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		while (i < BUFF_SIZE && buff[i] != '\n' && buff[i])
			i++;
		if (write_line(line, buff, i) == -1)
			return (-1);
		if (buff[i] == '\n' && (i == j - 1 || (j = nu_rst(&rest, fd, i, buff))))
			break ;
	}
	if (j < 0)
		return (-1);
	return ((*line || buff[0] == '\n') ? 1 : 0);
}
