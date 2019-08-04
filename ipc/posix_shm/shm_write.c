#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int fd;
    size_t len;
    char *addr;

    fd = shm_open(argv[1], O_RDWR, 0);
    if (fd == -1)
    {
        perror("shm_open");
        return 1;
    }

    len = strlen(argv[2]);

    if (ftruncate(fd, len) == -1)
    {
        perror("ftruncate");
        return 1;
    }

    printf("resizze to %ld bytes \n", len);

    addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

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

    printf("copying %ld bytes \n", (long)len);
    memcpy(addr, argv[2], len);
    exit(EXIT_SUCCESS);
}
