/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:46:19 by becamino          #+#    #+#             */
/*   Updated: 2023/05/22 18:51:50 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_cut(char *stash, int b_size)
{
	char	*line;
	char	*saved;
	int		i;

	i = 0;
	line = malloc(b_size);
	while(i < b_size - 1 && stash[i] != 10)
	{
			line[i] = stash[i];
			i++;
	}		
	line[i] = stash[i];
	saved = ft_save(stash, b_size, i);
	printf("\n %d", i);
	printf("\n %s", saved);
	
	return(line);
}

char	*ft_save(char *stash, int b_size, int i)
{
	static char	*temp;
	int	diff;
	int	x;
	
	b_size = b_size - 1;
	diff = b_size - i;
	
	x = 0;
	temp = malloc(diff);
	while (diff > 0)
	{
		temp[x] = stash[b_size];
		diff--;
		x++;
		b_size--;
	}
	return(temp);
}