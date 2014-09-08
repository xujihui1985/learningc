#include <stdio.h>
#include <stdlib.h>  //the conversion function is in the stdlib header


// convert string to number
int main() {
    // a to f   a stands for ascii
    double d = atof("123.456");
    // a to i
    int i = atoi("1234");

    printf("%.3f %d\n", d, i);
}

