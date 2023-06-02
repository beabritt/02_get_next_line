/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/06/01 19:56:19 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

char	*ft_save(char *stash)
{
	char	*aux;
	size_t	i;
	size_t	x;
	size_t	len;

	i = 0;
	x = 0;
	len = ft_strlen(stash);
	while(stash[i] != '\n')
		i++;
	aux = malloc(sizeof(char)*(len - i));
	if (!aux)
		return(NULL);
	while (i < len)
	{
		aux[x] = stash[i];
		x++;
		i++;
	}
	free(stash);
	return (aux);
}

char	*ft_cut(char *stash)
{
	int		i;
	int		len;
	char	*res;
	
	i = 0;
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

	return(res);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		readd[BUFFER_SIZE + 1];
	char		*line;
	int			x;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	x = 1;
	stash = malloc(sizeof(char) * 1);
	printf("hola\n");
	while (x > 0 && ft_strchr_gnl(stash, '\n') == 0)
	{
		x = read(fd, readd, BUFFER_SIZE);
		readd[BUFFER_SIZE] = '\0';
		stash = ft_strjoin_gnl(stash, readd);
	}	
	if (x == -1)
	{
		free(stash);
		return (NULL);
	}
	if (x == 0)
		return(stash);
	else
	{

		line = ft_cut(stash);
		stash = ft_save(stash);
	}
	printf("stash fnl: %s\n", stash);
	printf("line fnl: %s", line);
	return(line);	
}

#endif
