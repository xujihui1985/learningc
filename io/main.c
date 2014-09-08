#include <stdio.h>

int main() {
    printf("%d\n", 1111111);

    char* font = "dfafad";
    int size = 32;

    char* message = "hello world";

    char buffer[500];

    springf(buffer, 
            "<html><body><p style='font-family: %s;'></body></html>",
            font);

    printf("%s\n", buffer);

    return 0;
}
