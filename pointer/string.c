#include <stdio.h>

int string_length(char* string) {
    int length = 0;
    while(*string++) {
        ++length;
    }
    return length;
}

int main() {
    char string[] = "Hello world";

    printf("size %d\n", (int) sizeof(string));

    int length = 0;

    for(char* p = string; *p != 0; ++p) {
        ++length;
    }

    printf("length is %d", string_length("adfadfsad"));
    printf("length is %d", string_length("hi"));
}
