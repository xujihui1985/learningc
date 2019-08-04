#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int 
main(int argc, char** argv)
{

    FILE *fp = NULL;
    int fd, flags;
    if(argc < 2)
    {
        printf("invalid argment\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fd = fileno(fp);

    if (fd == -1)
    {
        printf("failed to convert fp to fd\n");
        exit(EXIT_FAILURE);
    }

    flags = fcntl(fd, F_GETFL);
    if((flags & O_NONBLOCK) == O_NONBLOCK)
    {
        printf("fd is nonblock\n");
    }
    else
    {
        flags |= O_NONBLOCK;
        fcntl(fd, F_SETFL, flags);
        flags = fcntl(fd, F_GETFL);
        if((flags & O_NONBLOCK) == O_NONBLOCK)
        {
            printf("fd is nonblock now\n");
        }
    }

}
