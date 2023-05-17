/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/05/17 17:20:45 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE	8

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	size_t	num;
	
	num = read(fd, stash, BUFFER_SIZE);
	printf("%s",stash);
	

	
	return(stash);
}