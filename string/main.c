#include <stdio.h>
#include <ctype.h>

int main(){
    char* message = "\"hello world\"\nGood bye \\you\\complete\\me //";

    printf("%s", message);

    for(char* p = message; *p; ++p) {
        char c = *p;
        printf("%c\t", c);
        if(isalnum(c)) printf("isalnum ");
        if(isalpha(c)) printf("isalpha ");
        if(islower(c)) printf("islower ");
        if(isupper(c)) printf("isupper ");
        if(isdigit(c)) printf("isdigit ");
        if(isxdigit(c)) printf("isxdigit ");
        if(iscntrl(c)) printf("iscntrl ");
        if(isgraph(c)) printf("isgraph ");
        if(isspace(c)) printf("isspace ");
        if(isblank(c)) printf("isblank ");
        if(isprint(c)) printf("isprint ");
        if(ispunct(c)) printf("ispunct ");

        printf("\n");
    }
}
