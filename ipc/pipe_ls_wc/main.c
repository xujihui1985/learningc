#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
    int fds[2];

    if(pipe(fds) == -1)
    {
        exit(EXIT_FAILURE);
    }

    switch(fork())
    {
        case -1:
            exit(EXIT_FAILURE);

        case 0:  // first child exec ls to write to pipe
            if(close(fds[0]) == -1)  // read end is unused, close it
            {
                exit(EXIT_FAILURE);
            }

            if(fds[1] != STDOUT_FILENO) // check if write end of pipe is not stdout
            {
                if(dup2(fds[1], STDOUT_FILENO) == -1) // dup write end of pipe to stdout
                {
                    exit(EXIT_FAILURE);
                }
                close(fds[1]); // close write end of pipe after dup to stdout
            }
            execlp("ls", "ls", (char *)NULL); // write to pipe
            exit(EXIT_FAILURE);

        default:  // parent fallback to create next child
            break;
    }

    switch(fork())
    {
        case -1:
            exit(EXIT_FAILURE);

        case 0:
            if(close(fds[1]) == -1) // write end is unused
            {
                exit(EXIT_FAILURE);
            }

            if (fds[0] != STDIN_FILENO)
            {
                if(dup2(fds[0], STDIN_FILENO) == -1)
                {
                    exit(EXIT_FAILURE);
                }
                close(fds[0]); //close after dup fd to stdin
            }
            execlp("wc", "wc", "-l", (char *)NULL); // read from pipe
            exit(EXIT_FAILURE);
        default:
            break;
    }

    // parent close unused fds and wait for children
    close(fds[0]);
    close(fds[1]);
    wait(NULL);  //wait for children
    wait(NULL);
}
