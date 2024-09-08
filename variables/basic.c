#include <stdio.h>

#define WORLD "mem.stat"

int local_variable() {
    static int hens;
    int eggs = 4;

    hens += 1;
    eggs += 1;

    printf("%d $d\n", hens, eggs);
}

int main() {

    char buf[100];
    local_variable();
    local_variable();
    local_variable();

    printf("hello world %s\n", "sean");

    int celsius, fahrenheit, kelvin;

    celsius = 21;
    
    printf("%.2f C = %.2f\n", 0.23f, 2.5f);

    snprintf(buf, 100, "/sys/fs/cgroup%s/"    WORLD, "/memory/xxx/bbb/ccc");

    printf("%s \n", buf);
}


float celsius_to_fahrenheit(float celsius) {
    return celsius * 10;
}


