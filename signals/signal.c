#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define _GNU_SOURCE
#define <string.h>

struct test_s{
	char* name;
	char* type;
};

static void
sigHandler(int sig)
{
    static int count = 0;

    if (sig == SIGINT)
    {
        count++;
        printf("caught SIGINT (%d)\n", count);
        raise(9);
        return;
    }

    printf("caught sigquit =\n");
    exit(EXIT_SUCCESS);
}

int 
main(int argc, char** argv) 
{
    char *str = strsignal(SIGINT);
    if(signal(SIGINT, sigHandler) == SIG_ERR)
    {
        exit(EXIT_FAILURE);
    }

    if (signal(SIGQUIT, sigHandler) == SIG_ERR)
    {
        exit(EXIT_FAILURE);
    }

    for(;;)
        pause();
}
