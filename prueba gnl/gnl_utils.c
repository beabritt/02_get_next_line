/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:46:19 by becamino          #+#    #+#             */
/*   Updated: 2023/06/01 13:28:22 by becamino         ###   ########.fr       */
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

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i ++;
		}
		dst [i] = '\0';
		return (ft_strlen(src));
	}
	else
		return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
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
	size_t	x;
	size_t	slen2;
	size_t	slen1;
	void	*s3;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	x = slen1 + slen2 + 1;
	s3 = malloc(x);
	if (!s3)
		return (0);
	ft_strlcpy_gnl (s3, s1, slen1);
	ft_strlcpy_gnl (&s3[slen1], s2, slen2);
	return (s3);
}