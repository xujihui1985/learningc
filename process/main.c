#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t parent_pid = getpid();
    printf("[PID %d] initializing process\n", parent_pid);

    pid_t pid = fork();
    if (pid < 0) {
        perror("failed to fork process");
        goto out_error;
    } else if(pid == 0) { // child process
        pid_t child_pid = getpid();
        printf("[PID %d] i'm child process\n", child_pid);
        exit(0);
    } else {
        printf("[pid %d] i am the parent process create child %d\n", parent_pid, pid);
        int child_status = 0;
        waitpid(pid, &child_status, 0);
        printf("child status is %d\n", child_status);
        exit(0);
    }
out_error:
    exit(1);

}
