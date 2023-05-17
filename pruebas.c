#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

int main()
{  
    int	fd;
    char buff[5];
  
    fd = open("hola.txt", O_RDONLY);
    read(fd, buff, 5);
    printf("\n%s\n",buff);
}