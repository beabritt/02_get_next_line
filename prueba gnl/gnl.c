/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/06/01 19:28:25 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

char	*ft_save(char *stash, int len, int i)
{
	char	*aux2;
	size_t	x;
	
	x = 0;
	aux2 = malloc(sizeof(char)*len);
	if (!aux2)
		return(NULL);
	while (i < len)
	{
		aux2[x] = stash[i];
		x++;
		i++;
	}
	free(stash);
	return (aux2);
}

char	*ft_cut(char *stash)
{
	int		i;
	int		j;
	int		len;
	char	*res;
	
	i = 0;
	j = 0;
	len = ft_strlen(stash);
	res = malloc(sizeof(char)* len);
	if (!res)
		return (NULL);
	while(stash[i] != '\n')
	{
		res[i] = stash[i];
		i++;
	}
	res[i] = stash[i];
	i++;
	res[i] = '\0';
	printf("%s\n", res);
	printf("%d\n", i);
	stash = ft_save (stash, len, i);
	return(res);
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
			//printf("%d\n", y);
		if (y == 1)
		{
			line = ft_cut(stash);
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
