/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/06/01 13:18:19 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

char	*ft_cut(char *stash, int b_size)
{
	char	*line;
	int		i;
	int		j;
	int		len;
	
	i = 0;
	j = 0;
	len = ft_strlen(stash);
	while(stash[i] != 10)
	{
			line[i] = stash[i];
			i++;
	}		
	line[i] = stash[i];
	while (i < len - 1)
	{
		stash[j] = stash[i];
		i++;
		j++;
	}
	
	printf("\n %s", line);
	
	return(line);
}

char	*ft_read(int fd, char *stash)
{
	char	readd[BUFFER_SIZE - 1];
	char	*line;
	int	x;
	int	y;
	
	x = 1;
	while (x > 0)
	{
		x = read(fd, readd, BUFFER_SIZE);
		stash = ft_strjoin_gnl(stash, readd);
		y = ft_strchr_gnl(stash, 10);
		if (y == 1)
			{
				line = ft_cut(stash);
				return(line);
			}
	}
	if (x == -1)
		return (NULL);
	if (x == 0)
		return(stash);
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			x;
	
	x = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = ft_read(fd, stash);
	
	printf("\n %s",line);
	printf("\n %s", stash);

	return(line);	
}

#endif
