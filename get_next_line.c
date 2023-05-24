/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/05/24 17:07:05 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	static char	saved[BUFFER_SIZE];
	char		*line;
	
	read(fd, stash, BUFFER_SIZE);
    line = ft_cut(stash, BUFFER_SIZE, saved);
	while(line[ft_strlen(line) != '\0'])
    {
        line = get_next_line(fd);   
    }	
	printf("%s\n",line);
	printf("%s\n", stash);
	printf("%s", saved);
	

	
	return(line);
}

#endif
