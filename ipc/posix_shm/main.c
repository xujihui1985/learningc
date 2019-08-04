#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

//./pshm_create -c /demo_shm 0
int
main(int argc, char *argv[])
{
    int flags, opt, fd;
    mode_t perms;
    size_t size;
    void *addr;

    flags = O_RDWR;
    while((opt = getopt(argc, argv, "cx")) != -1)
    {
        switch(opt)
        {
            case 'c': flags |= O_CREAT; break;
            case 'x': flags |= O_EXCL; break;
            default: return 1;
        }
    }

    if(optind + 1 >= argc)
    {
        printf("error \n");
    }

    size = 0;
    perms = (S_IRUSR | S_IWUSR);

    fd = shm_open(argv[optind], flags, perms);
    if (fd == -1)
    {
        printf("error shm_open\n");
        return 1;
    }

    if (ftruncate(fd, size) == -1)
    {
        printf("error ftruncate\n");
        return 1;
    }

    addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {

        perror("error mmap");
        return 1;
    }

    exit(EXIT_SUCCESS);
}
