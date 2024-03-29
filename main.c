/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:31:12 by becamino          #+#    #+#             */
/*   Updated: 2023/06/05 14:47:08 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     x;
    
    fd = open("hola.txt", O_RDONLY);
    if (!fd)
        return (0);
    while(x < 2)
    {
        line = get_next_line(fd);
        x++;
        printf("%s", line);
    }
    free(line);
    close(fd);
    return (0);
}
