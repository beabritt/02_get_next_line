/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:46:19 by becamino          #+#    #+#             */
/*   Updated: 2023/05/24 18:48:39 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_cut(char *stash, int b_size, char *saved)
{
	char		*line;
	static char	*temp;
	int			i;

	i = 0;
	line = malloc(b_size);
	while(i < b_size - 1 && stash[i] != 10)
	{
			line[i] = stash[i];
			i++;
	}		
	line[i] = stash[i];
	saved = ft_save(stash, b_size, i, temp);
	free(temp);
	//printf("\n %d", i);
	//printf("\n %s", saved);
	
	return(line);
}

char	*ft_save(char *stash, int b_size, int i, char *temp)
{
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

int	ft_strlen(char *line)
{
	int	cont;

	cont = 0;
	while(line[cont] != '\0')
	{
		cont++;
	}
	return(cont);
}