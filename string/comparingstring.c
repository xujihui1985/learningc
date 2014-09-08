#include <stdio.h>
#include <string.h>

int main() {
    char* message = "hello world";

    printf("size %d\n", (int) strlen(message));

    printf("Apples %d\n", strcmp(message, "Apples"));
    printf("Oranges %d\n", strcmp(message, "Orange"));
    printf("hello world %d\n", strcmp(message, "hello world"));
}
