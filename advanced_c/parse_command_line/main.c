#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>


int main(int argc, char **argv) {
  int option;
  // a: means args a have value
  // the first : is for default args
  while ((option = getopt(argc, argv, ":a:b")) != -1) {
    switch (option) {
      case 'a':
        printf("got a: %s\n", optarg);
        break;
      case 'b':
        printf("got b\n");
        break;
      case '?':
        printf("ERROR\n");
        break;
    }

  }


  for (int i = optind; i < argc; i++) {
    printf("%d: %s\n", i, argv[i]);
  }

  return 0;
}

