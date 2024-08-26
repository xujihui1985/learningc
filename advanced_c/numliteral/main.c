#include <stdio.h>
#include <stdint.h>

int main() {
  int32_t a = 123;
  uint32_t e = 123;
  int64_t b = 0xffaa33;
  int c = 0755;
  int d = 0b0101;

  printf("%d\n", a);
  printf("%ld\n", b);
  printf("%o\n", c);
  printf("%b\n", a);
}
