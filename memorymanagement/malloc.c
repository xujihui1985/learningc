#include <stdio.h>
#include <stdlib.h>

int main() {
    int* p = (int*) malloc(4); //if the result is 0, then its faile to initilize the variable

    *p = 42;

    free(p);
    p = 0; // remember to point p to 0 or null after free
    /* the reason is, after free, the memeory of the p pointer point has been released, but the p is still point to 
     * that address, the worst thing if we don't point p to zero, is the address of the p it point will be assigned to
     * another object, and if we use the p later, bad thing happened*/

    void* frame = malloc(1514);

    free(frame);
    frame = 0;

    char* message = (char*) malloc(141);

    free(message);
    message = 0;
    free(message); //

}

