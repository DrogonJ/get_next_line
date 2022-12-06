/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:13:00 by ngalzand          #+#    #+#             */
/*   Updated: 2022/11/23 14:29:46 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*remake_temp(char *temp)
{
	char	*newtemp;
	size_t	i;
	size_t	j;

	newtemp = 0;
	i = 0;
	j = contain_char(temp) + 1;
	newtemp = (char *)ft_calloc((ft_strlen(temp) - j) + 1, sizeof(char));
	if (!newtemp)
		return (ft_freetmp(&temp, 0, 0));
	while (temp[j])
	{
		newtemp[i] = temp[j];
		i++;
		j++;
	}
	ft_freetmp(&temp, 0, 0);
	return (newtemp);
}

char	*create_newline(char *temp)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!temp || temp[0] == 0)
		return (0);
	if (contain_char(temp) == -1)
		line = (char *)ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	else
		line = (char *)ft_calloc(contain_char(temp) + 2, sizeof(char));
	if (!line)
		return (0);
	while (temp[i] && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (contain_char(temp) >= 0)
		line[i] = '\n';
	return (line);
}

int	read_next_line(int fd, char **temp)
{
	char	*buffer;
	int		readval;

	readval = -1;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (-1);
	readval = read(fd, buffer, BUFFER_SIZE);
	if (readval >= 0)
		*temp = ft_strjoin(*temp, buffer);
	free(buffer);
	return (readval);
}

char	*get_next_line(int fd)
{
	static char	*temp[256];
	char		*line;
	int			readval;

	readval = -2;
	line = 0;
	while (!line && readval != 0 && readval != -1 && (fd >= 0 && fd <= 255))
	{
		readval = read_next_line(fd, &temp[fd]);
		if (readval == -1)
			return (ft_freetmp(&temp[fd], 0, 0));
		else if (readval == 0 || (readval >= 1 && contain_char(temp[fd]) >= 0))
		{
			line = create_newline(temp[fd]);
			if (!line)
				return (ft_freetmp(&temp[fd], 0, 0));
			if (temp[fd] && contain_char(temp[fd]) >= 0)
				temp[fd] = remake_temp(temp[fd]);
			else if ((readval == 0 && contain_char(temp[fd]) == -1))
				ft_freetmp(&temp[fd], 0, 0);
		}
	}
	return (line);
}
