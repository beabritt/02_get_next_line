/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/05/19 19:09:40 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE	5

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*line;
	size_t		num;
	
	num = read(fd, stash, BUFFER_SIZE);
	
	line = ft_cut(stash, BUFFER_SIZE);
	printf("%s",line);
	

	
	return(line);
}
#endif