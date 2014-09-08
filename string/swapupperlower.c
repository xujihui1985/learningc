#include <stdio.h>
#include <ctype.h>

int main() {
    char  message[] = "Hello World!";

    for(char* p = message; *p; ++p) {
        //char c = *p;
        //printf("%c\t", *p);
        //*p = (char) tolower(*p);
        if(isupper(*p)) *p = (char) tolower(*p);
        else if(islower(*p)) *p = (char) toupper(*p);
    }

    printf("%s", message);
}

