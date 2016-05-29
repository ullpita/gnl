/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:45:55 by upierre-          #+#    #+#             */
/*   Updated: 2016/05/29 17:48:21 by upierre-         ###   ########.fr       */
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
	static int		i = 0;
	static char		*suite = NULL;
	int				k;
	//static t_gnl	gnl = (t_gnl){0, NULL};

	if (fd < 0)
		return (-1);
	if (suite == NULL)
		suite = initialize(fd);
	if (suite == NULL)
		return (-1);
	j = i;
	while (suite[i] != '\n' && suite[i] != '\0')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * ((i - j) + 1))))
		return (-1);
	(*line)[i - j] = '\0';
	k = 0;
	if (i - j == 0)
		return (0);
	k = 0;
	while (suite[j] != '\n')
	{
		(*line)[k] = suite[j];
		if (suite[j] == '\0')
			return (1);
		j++;
		k++;
	}
	i++;
	return (1);
}
