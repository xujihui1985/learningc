#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <assert.h>
#include <fnmatch.h>
#include <glob.h>


int main(void) {
  regex_t preg;
  //assert(regcomp(&preg, "hello*", REG_EXTENDED) == 0);
  assert(regcomp(&preg, "hello*", REG_ICASE | REG_EXTENDED) == 0);

  int res = regexec(&preg, "HELLO!", 0, NULL, 0);
  if (res == 0) {
    printf("match\n");
  } else if (res == REG_NOMATCH) {
    printf("no match\n");
  }

  regfree(&preg);
  return 0;
}

void match_group() {

  regex_t preg;
  assert(regcomp(&preg, "(ab+)(cd+)", REG_ICASE | REG_EXTENDED) == 0);

  const size_t num_match = 10;
  regmatch_t pmatch[num_match + 1];

  char *s = "abbcdddddd";

  int res = regexec(&preg, s, num_match, pmatch, REG_ICASE);
  if (res == 0) {
    printf("match\n");
    // rm_so  start of match
    // rm_eo  end of match
    for (size_t i = 0; pmatch[i].rm_so != -1 && i < num_match; i++) {
      char buf[256] = {0};
      strncpy(buf, s + pmatch[i].rm_so, pmatch[i].rm_eo- pmatch[i].rm_so);
      printf("start %d, end %d: %s\n", pmatch[i].rm_so, buf);
    }
  } else if (res == REG_NOMATCH) {
    printf("no match\n");
  }
  regfree(&preg);
}

void fn_match(void) {
  char *s = "aaa bbb";
  int res = fnmatch("aa*", s, 0);
  if (res == 0) {
    printf("match\n");
  } else if (res == FNM_NOMATCH) {
    printf("nomatch\n");
  }
}

void fn_match_pathname(void) {
  char *s = "path/to/file";
  // char *s = "path/to/.file";
  int res = fnmatch("path/*/.file", s, FNM_PATHNAME | FNM_PERIOD);
  if (res == 0) {
    printf("match\n");
  } else if (res == FNM_NOMATCH) {
    printf("nomatch\n");
  }
}

int errfunc(const char *epath, int eerrno) {
  printf("error for %s: %s", epath, strerror(eerrno));
  // whether continue return 0 to continue or 1 to stop;
  return 0;
}

void glob_example() {
  glob_t pglob;

  int result = glob("*.c", 0, errfunc, &pglob);
  // gl_pathv  path count
  // gl_pathv  path value
  for (size_t i = 0; i < pglob.gl_pathc; i++) {
    printf("%zu: %s\n", i, pglob.gl_pathv[i]);
  }
  globfree(&pglob);
}
