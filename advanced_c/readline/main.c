#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main() {
  FILE *f = fopen("/etc/passwd", "r");

  assert(f != NULL);

  char *line = NULL;
  size_t line_len = 0;
  ssize_t read_size = 0;

  while((read_size = getline(&line, &line_len, f)) != -1) {
    line[read_size - 1] = '\0';
    printf("line='%s'\n", line);
  }
  free(line);
  assert(feof(f));
  fclose(f);
  return 0;
}
