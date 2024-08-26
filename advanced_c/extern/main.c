// c libraries are not compatible with c++
// so you would like to make them compatible
/*
 * g++ main.c t.o
clang: warning: treating 'c' input as 'c++' when in C++ mode, this behavior is deprecated [-Wdeprecated]
Undefined symbols for architecture arm64:
  "add(int, int)", referenced from:
      _main in main-90ad42.o
   NOTE: found '_add' in t.o, declaration possibly missing 'extern "C"'
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
 * */

#include <stdio.h>
#include "t.h"

int main() {
  int result = add(1, 2);
  return 0;
}
