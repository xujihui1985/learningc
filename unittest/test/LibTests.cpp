#define CATCH_CONFIG_MAIN

#include "catch.hpp"

extern "C" {
#include "../lib/lib.h"

char* fake_world() {
    return "fake world";
}

}

TEST_CASE("test is a test") {
    char *res = hello();
    REQUIRE(res == "world");
}
