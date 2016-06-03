/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:45:55 by upierre-          #+#    #+#             */
/*   Updated: 2016/06/03 18:58:24 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*initialize(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		len;
	char	*data;
	char	*tmp;

	data = ft_strdup("");
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = '\0';
		tmp = ft_strjoin(data, buff);
		free(data);
		data = tmp;
	}
	if (len == -1)
		return (NULL);
	return (data);
}

int		get_next_line(int fd, char **line)
{
	size_t			j;
	static t_gnl	gnl = (t_gnl){0, NULL};

	if (fd < 0 || (gnl.suite == NULL && (gnl.suite = initialize(fd)) == NULL))
		return (-1);
	j = gnl.i;
	while (gnl.suite[gnl.i] != '\n' && gnl.suite[gnl.i] != '\0')
		(gnl.i)++;
	if (!(*line = (char *)malloc(sizeof(char) * ((gnl.i - j) + 1))))
		return (-1);
	(*line)[gnl.i - j] = '\0';
	if ((gnl.i - j == 0) && gnl.suite[gnl.i] == '\0')
		return (0);
	ft_memcpy(*line, gnl.suite + j, gnl.i - j);
	(gnl.i)++;
	return (1);
}

