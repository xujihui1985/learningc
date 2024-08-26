#include <stdio.h>
#include <stdbool.h>


typedef enum {
  FLAG_A = (1 << 0),
  FLAG_B = (1 << 1),
  FLAG_C = (1 << 2),
} t_flag;


int f(int x, t_flag flags) {
  if (flags & FLAG_A) {
    x += x;
    flags &= ~FLAG_A; // unset FLAG_A
  }

  if (flags & FLAG_B)
    x *= x;
  if (flags & FLAG_C)
    x = ~x;
  return x;
}

int main(void) {
  f(123, 0);
  f(123, FLAG_A);
  f(123, FLAG_B | FLAG_C);
  return 0;
}
