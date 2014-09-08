#include <stdio.h>

typedef enum {
    TheInteger,
    TheCharacter
} WhichThing;

int main() {
    WhichThing type = TheInteger;

    type = TheCharacter;

}
