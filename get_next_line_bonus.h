/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:12:51 by ngalzand          #+#    #+#             */
/*   Updated: 2022/11/22 13:13:22 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
int			read_next_line(int fd, char **temp);
char		*create_newline(char *temp);
char		*remake_temp(char *temp);
size_t		ft_strlen(const char *s);
char		*ft_freetmp(char **temp, char **line, int freeline);
long int	contain_char(char *s);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);

#endif
