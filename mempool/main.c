#include <stdio.h>
#include "pool.h"
#include "mempool.h"
#include "log.h"

int test_pool(int element_size, int block_size) {
    pool p = {0};
    pool_initialize(&p, element_size, block_size);

    int *test_ptr1 = NULL;
    int *test_ptr2 = NULL;
    int *test_ptr3 = NULL;
    int *test_ptr4 = NULL;
    int *test_ptr5 = NULL;
    test_ptr1 = pool_malloc(&p);
    pool_free(&p, test_ptr1);
    test_ptr2 = pool_malloc(&p);
    test_ptr3 = pool_malloc(&p);
    test_ptr4 = pool_malloc(&p);
    test_ptr5 = pool_malloc(&p);
    test_ptr5 = pool_malloc(&p);
    test_ptr5 = pool_malloc(&p);
    test_ptr5 = pool_malloc(&p);
    test_ptr5 = pool_malloc(&p);
    test_ptr5 = pool_malloc(&p);

    if (!(test_ptr1 && test_ptr2 && test_ptr3 && test_ptr4 && test_ptr5)) {
        tprintf("DEBUG", DEBUG_SCREEN, "failed to allocation %s", "aaaaa");
        return -1;
    }

    pool_free(&p, test_ptr1);
    pool_free_pool(&p);
    return 0;
}

int test_pool2() {
    pool_t *pool = mem_pool_init(100, sizeof(int));
    int *res = (int *)mempool_malloc(pool);
    res = (int *)mempool_malloc(pool);
    if (res == NULL) {
        tprintf("DEBUG", DEBUG_SCREEN, "failed to allocation %s", "res");
        return -1;
    }
    mempool_free(pool, (char *)res);
    return 0;
}

int main() {

    int res = test_pool2();
    if (res == 0) {
        tprintf("DEBUG", DEBUG_SCREEN, "allocation %s success", "aaaaa");
    }

}