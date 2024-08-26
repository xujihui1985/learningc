#include <stdio.h>

#define PRINTF_LOOP(iter, ...) do \
  for (int i = 0; i < (iter); i++) \
       printf(__VA_ARGS__); \
} while(0)

int main(void) {
  return 0;
}
