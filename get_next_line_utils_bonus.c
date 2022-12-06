/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:12:44 by ngalzand          #+#    #+#             */
/*   Updated: 2022/11/23 14:30:00 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_freetmp(char **temp, char **line, int freeline)
{
	if (*temp)
		free(*temp);
	*temp = 0;
	if (freeline == 1)
	{
		if (*line)
			free(*line);
		*line = 0;
	}
	return (0);
}

long int	contain_char(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	if (((s2 && s2[0] == 0) || !s2) && s1)
		return (s1);
	else if (((s2 && s2[0] == 0) || !s2) && !s1)
		return (0);
	if (!s1)
		s1 = (char *)ft_calloc(1, 1);
	if (!s1)
		return (0);
	ptr = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!ptr)
		return (ft_freetmp(&s1, 0, 0));
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ft_freetmp(&s1, 0, 0);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	finalsize;

	i = 0;
	finalsize = count * size;
	ptr = malloc(finalsize);
	if (!ptr)
		return (0);
	while (i < finalsize)
	{
		*((char *)(ptr + i)) = 0;
		i++;
	}
	return (ptr);
}
