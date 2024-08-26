#include <stdio.h>
#include <stdbool.h>

enum tag {
  TAG_BOOL,
  TAG_INT,
  TAG_FLOAT,
};

struct dynamic {
  enum tag tag;
  union {
    bool b;
    int i;
    float f;
  } value; // value can be ommit
};

int main(void) {

  struct dynamic d = {
    .tag = TAG_INT,
    .value.i = 123,
  };

  switch(d.tag) {
    case TAG_BOOL:
      printf("bool %d\n", d.value.b);
      break;
    case TAG_INT:
      printf("int %d\n", d.value.i);
      break;
    case TAG_FLOAT:
      printf("float %f\n", d.value.f);
      break;
  }

  return 0;
}
