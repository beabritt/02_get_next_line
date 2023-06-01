/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/06/01 16:19:19 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

char	*ft_cut(char *stash, char *line)
{
	int		i;
	int		j;
	int		len;
	
	i = 0;
	j = 0;
	len = ft_strlen(stash);
	printf("%s\n", "hola");
	while(stash[i] != 10)
	{
			line[i] = stash[i];
			i++;
	}		
	line[i] = stash[i];
	i++;
	line[i] = '\0';
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
	char	readd[BUFFER_SIZE + 1];
	char	*line;
	char 	*aux;
	int	x;
	int	y;
	
	line = NULL;
	x = 1;
	while (x > 0)
	{
		x = read(fd, readd, BUFFER_SIZE);
		readd[BUFFER_SIZE] = '\0';
		if (stash)
		{
			aux = ft_strjoin_gnl(stash, readd);
			free (stash);
			stash = aux;
		}
		else
			stash = ft_strjoin_gnl(stash, readd);
		y = ft_strchr_gnl(stash, 10);
		if (y == 1)
		{
			line = ft_cut(stash, line);
			return(line);
		}
	}
	if (x == -1)
		free(stash);
		return (NULL);
	if (x == 0)
		return(stash);
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;
	int			x;
	
	x = 0;
	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	str = ft_read(fd, stash);
	
	/* printf("\n %s",str);
	printf("\n %s", stash); */

	return(str);	
}

#endif
