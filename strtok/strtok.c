#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_token(char *line);
unsigned getbits(unsigned x, int p, int n);

struct rb_node {
        unsigned long  __rb_parent_color;
        struct rb_node *rb_right;
        struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long))));

int main() {
    /*char *line, *dest;*/
    /*line = "hello world";*/
    /*printf("line %s\n",line);*/
    /*dest = malloc(strlen(line) + 1);*/
    /*if (dest == NULL) {*/
        /*printf("failed to alloc memory");*/
        /*exit(1);*/
    /*}*/
    /*memset(dest, '\0', strlen(line) + 1);*/
    /*strncpy(dest, line, strlen(line) + 1);*/
    /*printf("dest %s\n",dest);*/

    /*print_token(dest);*/
    unsigned b;
    b = getbits(208, 6, 3);
    printf("get bit %d\n", b);
    printf("~0 %d\n", 13 & ~3);

    printf("aaa %ld\n", sizeof(long));
    printf("bbb %ld\n", sizeof(void*));
    printf("cccc %ld\n", sizeof(struct rb_node));
    return 0;
}

void print_token(char *line) {
    static char whitespace[] = " \t\f\r\v\n";
    char *token;

    for (token = strtok(line, whitespace); token != NULL; token = strtok(NULL, whitespace)) {
        printf("next token is %s\n", token);
    }
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}
