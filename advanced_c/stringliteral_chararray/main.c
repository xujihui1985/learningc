#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *literal = "this is string literal";  // .rodata
  char array[] = "this is char array"; // .TEST
  array[0] = '#';

  char *s = strdup(literal);
  s[0] = '#';

  printf("%s\n", literal);
  printf("%s\n", array);
  printf("%s\n", s);

  free(s);
}
