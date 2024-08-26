#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_sep();

int main() {
  char s[] = "1,2,3,4,5";

  char *token = strtok(s, ",");
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ",");
  }

  str_sep();

  return 0;
}

void str_sep() {

  char s[] = "1,2,3,4,5";
  char *s_ptr = s;
  char *token;
  while((token = strsep(&s_ptr, ",")) != NULL) {
    printf("%s\n", token);
  }
}
