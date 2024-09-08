#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int COUNTER = 0;
void sigint_handler(int signal)
{
    printf("%s received reset counter\n", strsignal(signal));
    COUNTER = 0;
    exit(0);
}

int main()
{
    struct sigaction action;
    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask); // clear the mask
    // action.sa_flags = SA_RESTART;

    sigaction(SIGINT, &action, NULL);

    printf("starting counter\n");
    sigset_t block_mask;
    sigaddset(&block_mask, SIGINT);
    while(1) {
        COUNTER += 1;
        printf("counter %d\n", COUNTER);
        sigprocmask(SIG_BLOCK, &block_mask, NULL);
        sleep(1);
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);
    }
}

void ignore_all_but_sighub() 
{
    sigset_t block_mask;
    sigfillset(&block_mask); // fill all signal found on current machine
    sigdelset(&block_mask, SIGHUP); // delete sighub on block mask
    sigprocmask(SIG_BLOCK, &block_mask, NULL); // block the the signal of block_mask
    while(1) {
        printf("in the critical path\n");
        sleep(1);
    }
    sigprocmask(SIG_UNBLOCK, &block_mask, NULL); // unblock the signal after finish process
}
