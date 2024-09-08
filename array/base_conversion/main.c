#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100

#define foreach_string(iter, ...)\
    for (char **iter = (char*[]){__VA_ARGS__, NULL}; *iter; iter++)

#define fn_apply(type, fn, ...) \
    void *stopper_for_apply = (int[]){0}; \
    type **list_for_apply = (type*[]){__VA_ARGS__, stopper_for_apply}; \
    for (int i = 0; list_for_apply[i] != stopper_for_apply; i++) \
        fn(list_for_apply[i])

#define free_all(...) fn_apply(void, free, __VA_ARGS__);

#define zero_array(type, len) \
    int length = len; \
    type type##_array[len]; \
    memset(type##_array, 0, length*sizeof(type));

struct Hello {
    int age;
    int date;
    char name[MAX_NAME_SIZE];
};

int main() {

    double *x = malloc(10);
    double *y = malloc(10);

    free_all(x, y);

    zero_array(int, 10);

    printf("int_array %ld\n", sizeof(int_array));

    char *str = "thread";
    foreach_string(i, "yarn", str, "rope"){
        printf("%s\n", *i);
    }

    struct Hello hello = {
        .age = 123,
        .date = 23,
        .name = "hello"
    };

    const char base_digital[] = {
        '0', '1', '2', '3','4','5',
        '6', '7', '8', '9', 'A', 'B',
        'C', 'D', 'E', 'F'
    };

    int converted_number[64];
    long int number_to_convert;

    int next_digital, base, index = 0;

    printf("number to convert ");
    scanf("%ld", &number_to_convert);

    printf("base ");
    scanf("%i", &base);

    do {
        converted_number[index++] = number_to_convert % base;
        number_to_convert = number_to_convert / base;
    } while(number_to_convert != 0);

    printf("%d\n", index);
    for (--index; index >= 0; --index) {
        next_digital = converted_number[index];
        printf("%c", base_digital[next_digital]);
    }

}
