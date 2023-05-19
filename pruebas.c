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
	printf("%d \n", i);
	
	return(line);
}


int	main(void)
{
	static char	stash[] = "hola \n adios";
	char		*line;
	int			b_size;

	b_size = 8;
	line = ft_cut(stash, b_size);
	printf("%s", line);
	free(line);
	return(0);
}