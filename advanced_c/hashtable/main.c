#include <stdio.h>
#include <search.h>

int main() {
  hcreate(30);
  int val = 1;
  ENTRY entry = {
    .key = "hello",
    .data = (void *)&val,
  };
  ENTRY *res = hsearch(entry, ENTER);
  printf("%s -> %p\n", res->key, res->data);

  res = hsearch(entry, FIND);
  printf("found %s -> %p\n", res->key, res->data);
  hdestroy();
  return 0;
}
