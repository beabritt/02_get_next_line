/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:46:19 by becamino          #+#    #+#             */
/*   Updated: 2023/06/01 16:17:04 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"




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

void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst [i] = '\0';
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gnl(const char *s, int c)
{
	const int	slen = ft_strlen(s);
	int			x;

	x = 0;
	while (x <= slen && (x >= 0 && x <= 255))
	{
		if (s[x] == (char)c)
			return (1);
		else
			x++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*s3;
	int		x;
	int		j;
	
	s3 = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!s3)
		return (0);
	x = 0;
	while (s1 && s1[x])
	{
		s3[x] = s1[x];
		x++;
	}
	j = 0;
	while (s2[j])
	{
		s3[x + j] = s2[j];
		j++;
	}
	s3[x + j] = '\0';
	return (s3);
}