/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:45:55 by upierre-          #+#    #+#             */
/*   Updated: 2016/05/30 18:01:27 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*initialize(fd)
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
		return NULL;
	return (data);
}

int		get_next_line(int fd, char **line)
{
	size_t			j;
	int				k;
	static t_gnl	gnl = (t_gnl){0, NULL};

	if (fd < 0 || (gnl.suite == NULL && (gnl.suite = initialize(fd)) == NULL))
		return (-1);
	j = gnl.i;
	while (gnl.suite[gnl.i] != '\n' && gnl.suite[gnl.i] != '\0')
		(gnl.i)++;
	if (!(*line = (char *)malloc(sizeof(char) * ((gnl.i - j) + 1))))
		return (-1);
	(*line)[gnl.i - j] = '\0';
	if (gnl.i - j == 0)
		return (0);
	k = 0;
	while ((gnl.suite)[j] != '\n')
	{
		(*line)[k] = (gnl.suite)[j];
		if (gnl.suite[j] == '\0')
			return (1);
		j++;
		k++;
	}
	(gnl.i)++;
	return (1);
}/*

int		main(void)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
	}
}*/
