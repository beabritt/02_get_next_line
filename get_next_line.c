/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/05/22 18:26:16 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*line;
	size_t		num;
	
	num = read(fd, stash, BUFFER_SIZE);
	
	line = ft_cut(stash, BUFFER_SIZE);
	printf("\n %s",line);
	printf("\n %s", stash);
	

	
	return(line);
}

#endif
