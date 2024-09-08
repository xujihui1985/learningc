#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int (*func) (int, void *);
    void *context;
} lambda_t;

static int multiple(int left, void *ctx) {
    return left * (*(int *) ctx);
}

#define lambda(return_type, context_type, context_ptr, func_ptr) \
 ({                                                            \
  lambda_t l = { \
    .func = func_ptr, \
    .context = (void *) context_ptr}; \
  l;  \
 }) \

int *map(int *arr, int size, lambda_t lambda_func) {
     int *result = malloc(size * sizeof(int));
     if (result == NULL) {
         fprintf(stderr, "malloc failed\n");
         return NULL;
     }

     for(int i = 0; i < size; i++) {
         result[i] = lambda_func.func(arr[i], lambda_func.context);
     }
     return result;
 }

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int ctx = 3;

    lambda_t tripler = lambda(int, int, &ctx, multiple);

    int *tripled = map(arr, size, tripler);
    if (tripled == NULL) {
        return EXIT_FAILURE;
    }

    printf("result: ");
    for (int i = 0; i < size; i++) {
        printf("%d\n", tripled[i]);
    }
    free(tripled);
    return EXIT_SUCCESS;
}
