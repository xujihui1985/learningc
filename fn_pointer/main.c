#include <stdio.h>
#include <stdbool.h>

typedef struct Coffee_t {
    int id;
    char* name;
    bool isOn;

    void (*print)(const struct Coffee_t* self);

} Coffee;

void print_coffee(const Coffee* self) {
    printf("Coffee: %s\n", self->name);
}

void exec(const Coffee* coffee) {
    coffee->print(coffee);
}

int main(void) {
    Coffee coffee = { 
        .id = 1,
        .name = "Coffee",
        .isOn = true,
        .print = &print_coffee,
     };

    exec(&coffee);
    return 0;
}

