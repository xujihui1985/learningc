#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
    int fd;
    size_t len;
    char *addr;
    struct stat sb;
    char *res = NULL;

    fd = shm_open(argv[1], O_RDONLY, 0);
    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    if(fstat(fd, &sb) == -1)
    {
        perror("fstat");
        return 1;
    }

    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);

    if (addr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("close");
        return 1;
    }

    res = (char *)calloc(1, sb.st_size + 1);
    memcpy(res, addr, sb.st_size);
    res[sb.st_size] = 0;

    printf("res: %s\n", res);

    exit(EXIT_SUCCESS);
}
