#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_help() {
  printf("this is help\n");
}

void print_version() {
  printf("this is version\n");
}

int main(int argc, char **argv) {

  char *output = NULL;

  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {"output", required_argument, 0, 'o'},
    {0, 0, 0, 0}
  };

  int option_index = 0;
  int opt;
  while ((opt = getopt_long(argc, argv, "hvo:", long_options, &option_index)) != -1) {
    switch (opt) {
      case 'h':
        print_help();
        break;
      case 'v':
        print_version();
        break;
      case 'o':
        output = optarg;
        printf("output is %s\n", output);
        break;
      default:
        print_help();
        exit(1);
    }
  }

  if (optind < argc) {
    printf("none option argument\n");
    while (optind < argc) {
      printf("%d\n", optind);
      printf("%s\n", argv[optind++]);
    }
  }


  return 0;
  
}

