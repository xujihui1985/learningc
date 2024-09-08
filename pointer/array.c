#include <stdio.h>

struct proc {
    long size;
    int id;
};

int* Print(int* begin, int* end) {
    //if the range is empty return the point with the value 0;
    if(begin == end) return 0;

    int* largest = begin;
    
    for(; begin != end; ++begin) {
        printf("%d\n", *begin);
        if(*largest < *begin) {
            largest = begin;
        }
    }
    return largest;
}

void sizeofproc() {
    printf("size of proc %ld\n", sizeof(struct proc));
}


int main() {
    sizeofproc();

    struct proc proc[3];


    struct proc *p;
    for(p = proc; p < &proc[3]; p++) {
        printf("p %ld, proc %ld, number is %ld\n", p, proc, p-proc);
    }
    /*int numbers[] = { 1, 2, 3, 4, 5 };*/

    /*int size = sizeof(numbers) / sizeof(numbers[0]);*/

    /*printf("the total length is %d\n", size);*/

    /*int* p = numbers; // numbers is the address of the first element in the array*/

    /*int* end = p + size;*/

    /*printf("the first element is %d\n", *p);  // dereference*/
    //printf("the last element is %d\n", *end);

    /*int* largest = Print(numbers, numbers+size);*/

    /*printf("the largest number is %d\n", *largest);*/

    /*for(; p != end; ++p) {*/
        /*printf("%d\n", *p);*/
    /*}*/

    /*printf("-----------------------");*/

    /*for(int i = 0; i < size; ++i) {*/
        /*printf("%d\n", numbers[i]);*/
    /*}*/

}
