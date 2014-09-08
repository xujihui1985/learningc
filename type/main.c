#include <stdio.h>


typedef unsigned char byte;

struct Pixel
{
    float X;
    float Y;
}

typedef struct {
    float X;
    float Y;
} Pixel;

typedef unsigined char byte;

struct struct {
    byte Red;
    byte Green;
    byte Blue;
} Color;


int main() {
    int i = 123;
    float f = 1.23f;
    double d = 2.34;
    char c = 'c';
    unsigned int ui = 123ui;
    short si = 123;
    long li = 123;

    Pixel p = { 10.0f, 20,0f };
    Color c = { 255, 120, 0 };

    float x = p.X;
    c.Blue = 128;

    /*unsigned char === byte*/

    byte b = 0x12;

    printf("%d (%d)\n", i, (int) sizeof(int));
    return 0;
}
