#include <stdio.h>

int add_int(int a, int b) { return a + b; }
int add_float(int a, int b) { return a + b; }
int add_double(int a, int b) { return a + b; }


#define add(a, b) _Generic((a), \
  int: add_int((a), (b)), \
  float: add_float((a), (b)), \
  double: add_double((a), (b)), \
  default: printf("invalid type\n") \
)


int main() {

  int ai = 1, bi = 2;
  float af = 1.2, bf = 2.3;
  double ad = 3.2, bd = 4.2;

  int result = add(ai, bi);
  printf("res is %d\n", result);

  return 0;
}
