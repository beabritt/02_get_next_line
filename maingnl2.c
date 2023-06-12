/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingnl2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:31:12 by becamino          #+#    #+#             */
/*   Updated: 2023/06/12 15:56:00 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int 	fd;
	int		x;
    char    *line;

	x = 0;
    fd = open("caca.txt", O_RDONLY);
    if (!fd)
        return (0);
	while (x <= 1)
	{
   		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		x++;
	}

    close(fd);
    return (0);
}
