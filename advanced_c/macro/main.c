#include <stdio.h>

#define ADD(x, y) (x + y)
#define MUL(x, y) ((x) * (y)) // add () around every parameter, as the parameter may also be an expression

// multi line macro, add do while around the macro to prevent variable collision, see #multi example
#define SUM_RANGE(start, end) do {      \
  int sum = 0;                          \
  for (int x = (start); x < (end); x++) \
    sum += x;                           \
  printf("sum %d\n", sum);              \
} while(0)

#define FOO(x, y) printf("%s + %s = %d\n", #x, #y, (x) + (y))
#define PREFIX(var_name) new_##var_name  // concat the var_name

#define GENERIC_ADD_FUNC(type) \
  type add_##type(type x, type y) { \
    return x + y; \
  }

GENERIC_ADD_FUNC(int);
GENERIC_ADD_FUNC(float);

int main(void) {

  int x = 5 * ADD(2, 3);
  int y = 5 * ADD(2, 3 + 2);

  printf("x %d\n", x);
  printf("y %d\n", y);

  // #multi example
  int sum = 10;
  SUM_RANGE(2, 10);

  int first = 1;
  int second = 2;
  // output first + second = 3
  // printf("%s + %s = %d\n", "first", "second", first + second)
  FOO(first, second);

  int PREFIX(foo) = 3;

  add_int(1,2);
  add_float(3,4);


  return 0;
}
