#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

static void get_strings(const char *in) {
    char *cmd;
    asprintf(&cmd, "%s", in);
    if (system(cmd))
        fprintf(stderr, "something wrong %s \n", cmd);
    free(cmd);
}

int main(int argc, char **argv) {
   get_strings(argv[1]);
}
