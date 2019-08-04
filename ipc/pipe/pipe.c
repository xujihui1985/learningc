#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 10

int 
main(int argc, char **argv)
{
    int fds[2];
    char buf[BUF_SIZE];
    ssize_t numRead;

    if (pipe(fds) == -1)
    {
        exit(EXIT_FAILURE);
    }

    switch(fork())
    {
        case -1:
            exit(EXIT_FAILURE);

        case 0: // child reads from pipe
            if (close(fds[1]) == -1)  // close the write end
            {
                exit(EXIT_FAILURE);
            }

            for(;;)
            {
                numRead = read(fds[0], buf, BUF_SIZE);
                if (numRead == -1)
                {
                    exit(EXIT_FAILURE);
                }
                if (numRead == 0)
                {
                    break; // eof
                }
                if(write(STDOUT_FILENO, buf, numRead) != numRead)
                {
                    exit(EXIT_FAILURE);
                }
            }
            write(STDOUT_FILENO, "\n", 1);
            if (close(fds[0]) == -1)
            {
                exit(EXIT_FAILURE); // failed to close read end
            }
            exit(EXIT_SUCCESS);
        default:
            if(close(fds[0]) == -1) // parent process write to pipe, close read end
            {
                exit(EXIT_FAILURE); 
            }
            if(write(fds[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
            {
                exit(EXIT_FAILURE); 
            }
            wait(NULL);    // wait for child to finish
            exit(EXIT_SUCCESS);
    }
}
