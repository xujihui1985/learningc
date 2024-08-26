#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>


int main() {
  DIR *dp;
  struct dirent *entry;
  struct stat fs;
  char *filename;
  int r;

  dp = opendir(".");

  if (dp == NULL) {
    printf("unable to read directory \n");
    return 1;
  }

  while((entry = readdir(dp)) != NULL) {
    filename = entry->d_name;
    r = stat(filename, &fs);
    if (r == -1) {
      fprintf(stderr, "error reading %s\n", filename);
      return 1;
    }

    if (S_ISDIR(fs.st_mode)) {
      printf(" Dir %-16s ", filename);
    } else {
      printf(" File %-16s ", filename);
    }

    printf("%8lu bytes ", fs.st_size);
    printf("%s", ctime(&fs.st_atimespec));

  }
  closedir(dp);



  return 0;

}
