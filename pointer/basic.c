#include <stdio.h>

int main() {
    int i = 1234;
    int* p = 0;

    *p = &i;

    int j = *p;

    *p = 2345; // change the value of the p point to in this case, change the value of i to 2345

}

