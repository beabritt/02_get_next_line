/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:48:57 by becamino          #+#    #+#             */
/*   Updated: 2023/05/31 17:31:48 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);

char	*ft_cut(char *stash, int b_size);
char	*ft_save(char *stash, int b_size, int i);

size_t	ft_strlen(const char *s);
int 	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);