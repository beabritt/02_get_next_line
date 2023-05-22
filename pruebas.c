#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>


char	*ft_cut(char *stash, int b_size)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(b_size);
	while(i < b_size - 1 && stash[i] != 10)
	{
			line[i] = stash[i];
			i++;
	}		
	line[i] = stash[i];
	stash = ft_save(stash, b_size, i);
	printf("\n %d", i);
	
	return(line);
}

char	*ft_save(char *stash, int b_size, int i)
{
	int	diff;
	int	x;
	
	b_size = b_size - 1;
	diff = b_size - i;
	
	x = 0;
	while (diff > 0)
	{
		stash[x] = stash[b_size];
		diff--;
		x++;
		b_size--;
	}
	return(stash);
}