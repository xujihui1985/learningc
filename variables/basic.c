#include <stdio.h>

int local_variable() {
    static int hens;
    int eggs = 4;

    hens += 1;
    eggs += 1;

    printf("%d $d\n", hens, eggs);
}

int main() {

    local_variable();
    local_variable();
    local_variable();

    printf("hello world %s", "sean");

    int celsius, fahrenheit, kelvin;

    celsius = 21;
    
    printf("%.2f C = %.2f", 0.23f, 2.5f);
}


float celsius_to_fahrenheit(float celsius) {
    return celsius * 10;
}


