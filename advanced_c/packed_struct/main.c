#include <stdio.h>
#include <stdint.h>


struct foo {
  int32_t b;
  int16_t c;
  int8_t a;
};

struct foo2 {
  int8_t a;
  int16_t c;
  int32_t b;
} __attribute__((packed));

int main() {
  struct foo f = {
    .a = 0x11,
    .b = 0x22222,
    .c = 0x3333,
  };

  printf("size of f is %zu\n", sizeof(f));
  uint8_t *as_bytes = (uint8_t *)&f;
  for (int i = 0; i < sizeof(f); i++) {
    printf("%x ", as_bytes[i]);
  }
}
