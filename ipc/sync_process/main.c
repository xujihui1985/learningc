#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int
main(int argc, char** argv)
{
    int fds[2];
    int j, dummy;

    setbuf(stdout, NULL);  // make stdout unbuffered, since we terminate child with _exit

    printf("parent started \n");

    if(pipe(fds) == -1)
    {
        exit(EXIT_FAILURE);
    }

    for(j = 1; j < argc; j++)
    {
        switch(fork())
        {
            case -1: 
                exit(EXIT_FAILURE);

            case 0: //child
                if(close(fds[0]) == -1)  // close read end
                {
                    exit(EXIT_FAILURE);
                }

                sleep(5);

                printf("child %d (PID=%ld) closing pipe \n", j, (long) getpid());

                if(close(fds[1]) == -1)
                {
                    exit(EXIT_FAILURE);
                }

                _exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    if(close(fds[1]) == -1)  // write end is unused
    {
        exit(EXIT_FAILURE);
    }

    if(read(fds[0], &dummy, 1) != 0)
    {
        printf("parent didn't get eof\n");
        exit(EXIT_FAILURE);
    }

    printf("parent ready to go\n");

    exit(EXIT_SUCCESS);
}
