#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    //FILE* f = stdout;
    FILE* f = fopen("message2.txt", "r");
    if(f == NULL) {
        perror("fopen()");
        fprintf(stderr, "fopen faile in file %s at line # %d\n", __FILE__, __LINE__-4);
        exit(EXIT_FAILURE);
    }

    fprintf(f, "hello world\n");
    fclose(f);

    return EXIT_SUCCESS;
        
}
