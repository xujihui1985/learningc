#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    char *addr;
    int fd;
    struct stat sb = {0};
    char buf[1000];


    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        return 1;
    }

    // obtain the size of the file and use it to specify the size of 
    // the mapping and the size of the buffer to be written
    //
    if (fstat(fd, &sb) == -1)
    {
        return 1;
    }

    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED)
    {
        return 1;
    }
    
    memcpy(buf, addr, 1000);
    buf[1000 - 1] = 0;

    printf("content %s\n", buf);

    exit(EXIT_SUCCESS);

}
