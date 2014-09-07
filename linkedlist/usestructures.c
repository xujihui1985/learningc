#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct list_element
{
    struct list_element* next;
};

typedef struct list_element list_element;

typedef struct 
{
    list_element* first;
    list_element* last;


} list;

void list_init(list* container)
{
    container->first = 0;
    container->last = 0;
}

bool list_empty(list* container)
{
    return 0 == container->first;
}

list_element* list_begin(list* container)
{
    return container->first;
}

list_element* list_next(list_element* element)
{
    return element->next;
}

void list_push_back(list* container, list_element* element)
{
    if(list_empty(container))
    {
        container->first = element;        
        container->last = element;        
    }
    else
    {
        container->last->next = element;
        container->last = element;
    }

    //printf(element->next);
    /*element->next = 0;*/
}

list_element* list_pop_front(list* container)
{
    list_element* element = container->first;
    container->first = container->first->next;
    return element;
}


typedef struct {
    list_element header;
    int value;
} apple;

int main() 
{

    apple* a = (apple*) malloc(sizeof(apple));
    apple* b = (apple*) malloc(sizeof(apple));
    apple* c = (apple*) malloc(sizeof(apple));

    a->value = 1;
    b->value = 2;
    c->value = 3;
    
    list apples;
    list_init(&apples);
    list_push_back(&apples, &a->header);
    list_push_back(&apples, &b->header);
    list_push_back(&apples, &c->header);

    bool isEmpty = list_empty(&apples);
    //printf(isEmpty);

    for(a = (apple *) list_begin(&apples); a; a=(apple *) list_next(&a->header))
    {
        printf("%d\n", a->value);
    }

    while(!list_empty(&apples))
    {
        a = (apple *) list_pop_front(&apples);
        free(a);
    }

    return 0;
}
