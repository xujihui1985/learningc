#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *libHandler;
    void (*funcp)(void); // a function pointer that receive void and return void
    char const *err;  // err is a pointer to const of char (read from right to left)

    libHandler = dlopen("<dllocation>",RTLD_LAZY);

    if (libHandler == NULL)
    {
        printf("dlopen: %s", dlerror());
        return EXIT_FAILURE;
    }

    (void)dlerror(); // clear dlerror

    // However, for this code, gcc –pedantic warns that “ANSI C forbids the use of cast expressions as lvalues.” The *(void **) syntax doesn’t incur this warning because we are assigning to an address pointed to by the assignment’s lvalue.
    *(void **) (&funcp) = dlsym(libHandler, "funcname");

    err = dlerror();

    if (err != NULL)
    {
        printf("dlsym: %s\n", err);
        return EXIT_FAILURE;
    }

    (*funcp)();
    dlclose(libHandler);
    exit(EXIT_SUCCESS);
}
