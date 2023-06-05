/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/06/05 16:44:01 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *stash)
{
	char	*aux;
	size_t	i;
	size_t	x;
	size_t	len;

	i = 0;
	x = 0;
	len = ft_strlen(stash);
	while(stash[i] && stash[i] != '\n')
		i++;
	i++;
	aux = malloc(sizeof(char)*(len - i + 1));
	if (!aux)
		return(NULL);
	while (i < len)
	{
		aux[x] = stash[i];
		x++;
		i++;
	}
	if (x == 0)
		return (NULL);
	aux[x] = '\0';
	free(stash);
	return (aux);
}

char	*ft_cut(char *stash)
{
	int		i;
	int		len;
	char	*res;
	
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	len++;
	res = malloc(sizeof(char)* (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while(stash[i] != '\n' && stash[i])
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
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
		{
			free (stash);
			stash = NULL;
		}
		return (NULL);
	}
	x = 1;
	while (x > 0)
	{
		x = (int)read(fd, readd, BUFFER_SIZE);
		if (x == -1)
			return (ft_free(stash));
		if (x == 0)
			break ;
		readd[x] = '\0';
		stash = ft_strjoin_gnl(stash, readd);
		if (!stash)
			return (NULL);
		if (ft_strchr_gnl(stash, '\n') == 1)
			break ;
	}
	if (!stash)
		return (NULL);
	line = ft_cut(stash);
	stash = ft_save(stash);
	return(line);	
}
