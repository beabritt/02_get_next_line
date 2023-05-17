/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:31:12 by becamino          #+#    #+#             */
/*   Updated: 2023/05/17 17:15:47 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;

    fd = open("hola.txt", O_RDONLY);
    if (!fd)
        return (0);
    get_next_line(fd);
    close(fd);
    return (0);
}