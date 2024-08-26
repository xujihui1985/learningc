#include <stdio.h>
#include <errno.h>

int main(void) {

  FILE *f = fopen("./xx", "r");
  if (f == NULL) {
    printf("%d\n", errno);
    perror("errxxxxx");
    return 1;
  }
  fclose(f);

  return 0;
}
