#include <stdio.h>

struct S{
  int i;
  double d;
  char c;
};

int main() {

  printf("size %ld\n", sizeof(struct S));

  unsigned char bad_buff[sizeof(struct S)];
  _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

  struct S *bad_ptr = (struct S *)bad_buff;
  struct S *good_ptr = (struct S *)good_buff;

  printf("bad %p\n", bad_ptr);
  printf("good %p\n", good_ptr);
}
