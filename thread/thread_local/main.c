#include <pthread.h>
#include <stdio.h>

#define MAX_ERROR_LINE 255

// thread local specifier
static __thread char buf[MAX_ERROR_LINE];  //The __thread keyword must immediately follow the static or extern keyword, if either of these is specified in the variable’s declaration.

int
main()
{

    return 0;

}
