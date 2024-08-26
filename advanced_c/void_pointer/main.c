#include <stdlib.h>
#include <stdio.h>

void *my_memset(void *data, uint8_t c, size_t n) {
  uint8_t *data_as_bytes = (uint8_t*)data;
  for (size_t i = 0; i < n; i++) {
    data_as_bytes[i] = c;
  }
  return data;
}

void map(void *data, size_t n, size_t size, void (*f)(void *)) {
  uint8_t *data_as_bytes = (uint8_t*)data;
  for (size_t i = 0; i < n; i++) {
    f(&data_as_bytes[i * size]);
  }
}

void plus_one(void *p) {
  int* v = p;
  *v += 1;
}

int main(void) {

  int xs[5] = {1,2,3,4,5};

  int a = 3;
  void *p = &a;

  printf("%p \n", p);

  printf("%d \n", *((int *)p));

  my_memset(xs, 0, sizeof(xs));
  for (int i = 0; i < 5; i++) {
    printf("%d \n", xs[i]);
  }

  map(xs, 5, sizeof(int), plus_one);

  for (int i = 0; i < 5; i++) {
    printf("%d \n", xs[i]);
  }

  return 0;
}
