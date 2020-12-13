//
// Created by Sean on 12/13/20.
//

#include "lib.h"

#ifdef UNDER_TEST
extern char* fake_world();
#define WORLD fake_world
#else
#define WORLD world
#endif

char* world() {
    return "world";
}

char* hello() {
    return WORLD();
}

