#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 512

typedef struct keyval {
    char key[MAX_KEY_LENGTH];
    void *value;
    struct keyval *(*keyval_copy)(struct keyval const *in);
    void (*keyval_free)(struct keyval *in);
} keyval;

keyval *keyval_new(char key[], void *value){
    
}

typedef struct point {
    double x, y;

} point;

typedef struct {
    double z;
    union {
        struct {
            double x, y;
        };
        point p2;
    };
} threepoint;

void show_point(point* p) {
    printf("x is %lf, y is %lf\n", p->x, p->y);
}

int main() {
    threepoint p = {.x=3, .y=2, .z=5};
    show_point(&p.p2);

    int length = 6;
    int nums[length];
    nums[0] = 1;

    printf("n is %d\n", nums[0]);
}
