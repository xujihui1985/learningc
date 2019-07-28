#include <stdlib.h>
#include "pool.h"

#define MAX(a, b) ((a) < (b) ? (b) : (a))

void pool_initialize(pool *p, const uint32_t element_size, const uint32_t block_size) {
    uint32_t i;

    p->element_size = MAX(element_size, sizeof(poolFreed));
    p->block_size = block_size;  // block size 8

    pool_free_all(p);

    p->blocks_used = POOL_BLOCKS_INITIAL;    // blocks_used = 1
    p->blocks = malloc(p->block_size * p->blocks_used);  //

    for (i = 0; i < p->blocks_used; i++) {
        p->blocks[i] = NULL;
    }
}

void pool_free_pool(pool *p) {
    uint32_t i;
    for (i = 0; i < p->blocks_used; i++) {
        if (p->blocks[i] == NULL) {
            break;
        } else {
            free(p->blocks[i]);
        }
    }
    free(p->blocks);
}


void *pool_malloc(pool *p) {

    if (p->freed != NULL) {
        void *recycle = p->freed;
        p->freed = p->freed->nextFree;
        return recycle;
    }

    // used 是一个block中已经被使用的，每次malloc，used就+1， 如果used与block_size一样，说明一个block已经分配完，需要
    // 在新的block上分配
    if (++(p->used) == p->block_size) {
        // 重置 used
        p->used = 0;

        // 如果block用完了，那么需要扩block
        if (++(p->block) == (int32_t) p->blocks_used) {
            // 左移一位 按2的次方扩容
            p->blocks_used = p->blocks_used << 1u;
            // realloc block memory， 这里只是分配指针，并没有分配实际的block
            p->blocks = realloc(p->blocks, sizeof(uint8_t *) * p->blocks_used);

            // 初始化新allock的block为NULL
            for (uint32_t i = p->blocks_used >> 1u; i < p->blocks_used; i++) {
                p->blocks[i] = NULL;
            }
        }
        if (p->blocks[p->block] == NULL) {
            //分配block memory, 大小为element_size * block_size, 这里block_size
            //指的是一个block可以存下的element数量
            p->blocks[p->block] = malloc(p->element_size * p->block_size);
        }
    }

    // 返回当前block，还未被是用的block中，还未被使用的element地址
    return p->blocks[p->block] + p->used * p->element_size;
}

void pool_free(pool *p, void *ptr) {
    poolFreed *pFreed = p->freed;
    p->freed = ptr;
    p->freed->nextFree = pFreed;
}

void pool_free_all(pool *p) {
    p->used = p->block_size - 1;
    p->block = -1;
    p->freed = NULL;
}

