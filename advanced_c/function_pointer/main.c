#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*t_my_func)(int, int);

// int (*)(int, int) this is a functio type
int foo(int x, int y) {
  return x + y ;
}

void print_if(int xs[5], bool (*predicate)(const int)) {
  for (int i = 0; i < 5; i++) {
    if (predicate(xs[i])) {
      printf("%d\n", xs[i]);
    }
  }
}

bool is_even(const int v) {
  return v % 2 == 0;
}

int desc(const void* x1, const void* x2) {
  return (*(int*)x2) - (*(int*)x1);
}

int asc(const void* x1, const void* x2) {
  return (*(int*)x1) - (*(int*)x2);
}

int main(void) {
  int xs[] = {1,2,5,3,4};

  int len = sizeof(xs) / sizeof(int);

  qsort(xs, len, sizeof(int), desc);
  for (int i = 0; i < len; i++)
    printf("%d\n", xs[i]);

  qsort(xs, len, sizeof(int), asc);
  for (int i = 0; i < len; i++)
    printf("%d\n", xs[i]);


  print_if(xs, is_even);

  int (*f)(int, int) = foo;

  t_my_func f2 = foo;

  printf("the value of 2 + 4 is %d\n", f2(2,4));

  return 0;
}

