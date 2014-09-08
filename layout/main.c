#include <stdio.h>

typedef struct {
    short first;
    int second;
    short third;
} Layout;

typedef struct {
    short first;
    short thrid;
    int second;
} BetterLayout;

int main() {
    printf("short %d\n", (int) sizeof(short));  // 2
    printf("int %d\n", (int) sizeof(int));  // 4
    printf("Layout %d\n", (int) sizeof(Layout)); //12
    printf("BetterLayout %d\n", (int) sizeof(BetterLayout)); //8

    // it is strange that layout occupy 12 byte while short is 2 and int is 4,
    // that's because c compiler will auto line up the variable, that's means,
    // in order to lineup the int it add some padding on the first and third
    // short  -- xx__
    // int    -- xxxx
    // short  -- xx__
    //
    // so, it's better to swap the position of first and second, see BetterLayout
}
