//
// Created by Sean on 2019-07-28.
//

#ifndef MEMPOOL_MEMPOOL_H
#define MEMPOOL_MEMPOOL_H

typedef struct {
    int num_of_free; // number of free slots;
    int first; // the first free slot;
    int num_of_block; // the number of blocks
    int block_size; //block size in bytes
    int *free_list; // the index list
    char *pool; // the actual mem block
    pthread_mutex_t mutex;
} pool_t;

pool_t *mem_pool_init(int num_of_block, int block_size);

char *mempool_malloc(pool_t *pool);

void mempool_free(pool_t *pool, char *pMem);

void mempool_cleanup(pool_t *pool);

#endif //MEMPOOL_MEMPOOL_H
