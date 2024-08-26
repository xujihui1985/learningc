#include <stdio.h>
#include <assert.h>

#define FOO 3

static_assert(FOO == 3, "FOO is not 42");

int main() {
  return 0;
}
