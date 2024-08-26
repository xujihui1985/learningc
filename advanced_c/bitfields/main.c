#include <stdio.h>

struct foo {
  unsigned int first_4: 4;
  unsigned int next_4: 4;
  unsigned int alone: 1;
  unsigned int rest: 7;
};

int main() {
  struct foo f = {
    .first_4 = 15,
    .next_4 = 7,
    .alone = 1,
    .rest = 20,
  };

  printf("sizeof foo %zu \n",sizeof(f));

  return 0;
}
