#include <stdio.h>

enum foo {
  foo_2 = 0,
  foo_3,
  foo_4,
};

static int squares[] = {
  [foo_2] = 2,
  [foo_3] = 3,
  [foo_4] = 4,
  // be careful, if the index is too large, it will make the size of array very large, uncomment the line below
  // to see to size of squares
  // [1023] = 5,  
};

struct command_info {
  char* (*func)();
};

char* parse_line() {
  return "hello";
}

static const struct command_info command_info_lookup[] = {
  ['{'] = {parse_line},
};

static const char escape_lookup[] = {
  ['t'] = '\t',
  ['n'] = '\n',
  ['r'] = '\r',
  ['v'] = '\v',
  ['f'] = '\f',
};

int main() {
  printf("%d\n", squares[foo_2]);
  printf("%zu\n", sizeof(squares));

  char* res = command_info_lookup['{'].func();
  printf("res is %s\n", res);
  return 0;
}
