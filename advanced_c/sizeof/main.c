#include <stdio.h>

#define ARRAY_LEN(a) (sizeof(a) / sizeof(a[0]))
int main() {

  int a = 1;
  int xs[] = {1,2,3,4,5};
  int *xs_ptr = xs;

  printf("%zu\n", sizeof(a));
  printf("%zu\n", sizeof(xs));
  printf("%zu\n", ARRAY_LEN(xs));
  printf("%zu\n", sizeof(xs_ptr)); // you can not get the sizeof array by ptr
}
