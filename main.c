/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:31:12 by becamino          #+#    #+#             */
/*   Updated: 2023/05/24 17:00:41 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;
    char    *line;
    
    fd = open("hola.txt", O_RDONLY);
    if (!fd)
        return (0);
    line = get_next_line(fd);

    free(line);
    close(fd);
    return (0);
}
