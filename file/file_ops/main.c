#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  char *filename;
  struct stat fs;
  int r;

  if (argc < 2) {
    fprintf(stderr, "specify a filename \n");
    exit(1);
  }

  filename = argv[1];
  r = stat(filename, &fs);
  if (r == -1) {
    fprintf(stderr, "error reading '%s'\n", filename);
    exit(1);
  }

  printf("File '%s' is a ", filename);

  if(S_ISBLK(fs.st_mode)) {
    printf("block file\n");
  } else if(S_ISCHR(fs.st_mode)) {
    printf("char device\n");
  } else if(S_ISDIR(fs.st_mode)) {
    printf("dir\n");
  } else if(S_ISFIFO(fs.st_mode)) {
    printf("is fifo\n");
  } else if(S_ISREG(fs.st_mode)) {
    printf("is reg file\n");
  } else if(S_ISLNK(fs.st_mode)) {
    printf("is symbo link\n");
  } else if (S_ISSOCK(fs.st_mode)) {
    printf("is sock\n");
  } else {
    printf("unknown type \n");
  }

  printf("owner permissions: ");
  if (fs.st_mode & S_IRUSR) {
    printf("read ");
  }
  if (fs.st_mode & S_IWUSR) {
    printf("write ");
  }
  if (fs.st_mode & S_IXUSR) {
    printf("execute ");
  }
  putchar('\n');

  printf("group permissions: ");
  if (fs.st_mode & S_IRGRP) {
    printf("read ");
  }
  if (fs.st_mode & S_IWGRP) {
    printf("write ");
  }
  if (fs.st_mode & S_IXGRP) {
    printf("execute ");
  }
  putchar('\n');

  printf("other permissions: ");
  if (fs.st_mode & S_IROTH) {
    printf("read ");
  }
  if (fs.st_mode & S_IWOTH) {
    printf("write ");
  }
  if (fs.st_mode & S_IXOTH) {
    printf("execute ");
  }
  putchar('\n');

  return 0;
}
