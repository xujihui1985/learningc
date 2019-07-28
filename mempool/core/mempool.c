//
// Created by Sean on 2019-07-28.
//

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "mempool.h"

pool_t *mem_pool_init(int num_of_block, int block_size) {
    int i;
    pool_t *pool_p;

    if (num_of_block <= 1 || block_size <= 1) {
        tprintf("ERROR", DEBUG_SCREEN, "invalid parameter in mempool init");
        return NULL;
    }

    pool_p = (pool_t *) malloc(sizeof(pool_t));
    if (pool_p == NULL) {
        tprintf("ERROR", DEBUG_SCREEN, "mempool malloc failed");
        return NULL;
    } else {
        memset(pool_p, 0, sizeof(pool_t));
    }

    pool_p->block_size = block_size;
    pool_p->num_of_block = num_of_block;
    pool_p->pool = (char *) malloc((size_t) block_size * num_of_block);
    pool_p->free_list = (int *) malloc(sizeof(int) * num_of_block);

    if (pool_p->pool == NULL || pool_p->free_list == NULL) {
        tprintf("ERROR", DEBUG_SCREEN, "failed to allocate memory");
        free(pool_p->free_list);
        free(pool_p->pool);
        free(pool_p);
        return NULL;
    }

    pthread_mutex_init(&(pool_p->mutex), NULL);

    for (i = 0; i < pool_p->num_of_block; ++i) {
        pool_p->free_list[i] = i;
    }
    pool_p->first = 0;
    pool_p->num_of_free = pool_p->num_of_block;
    return pool_p;
}

char *mempool_malloc(pool_t *pool) {
    char *pos = NULL;
    pthread_mutex_lock(&(pool->mutex));

    if (pool->num_of_free <= 0) {
        tprintf("ERROR", DEBUG_SCREEN, "out of memory");
    } else {
        pos = pool->pool + (pool->block_size * (pool->free_list[pool->first]));
        pool->first++;
        pool->first = pool->first % pool->num_of_block;
        pool->num_of_free--;
    }
    pthread_mutex_unlock(&(pool->mutex));
    if (pos != NULL) {
        memset(pos, 0, (size_t) pool->block_size);
    }
    return pos;
}

void mempool_free(pool_t *pool, char *pMem) {
    int index;
    pool_t *pool_p = (pool_t *) pool;

    if (pMem == NULL) {
        return;
    }

    pthread_mutex_lock(&(pool_p->mutex));

    index = (int)(pMem - pool_p->pool) % pool_p->block_size;
    if (index != 0) {
        tprintf("ERROR", DEBUG_SCREEN, "invalid free address %p", pMem);
    } else {
        index = (int)(pMem - pool_p->pool) / pool_p->block_size;

        if (index < 0 || index >= pool_p->num_of_block) {
            tprintf("ERROR", DEBUG_SCREEN, "invalid free address %p", pMem);
        } else {
            pool_p->free_list[(pool_p->first + pool_p->num_of_free) % pool_p->num_of_block] = index;
            pool_p->num_of_free++;
            memset(pMem, 0, pool_p->block_size);
        }
    }
    pthread_mutex_unlock(&(pool_p->mutex));
}

void mempool_cleanup(pool_t *pool) {
    pthread_mutex_destroy(&(pool->mutex));
    if (pool->pool) free(pool->pool);
    if (pool->free_list) free(pool->free_list);
    memset(&pool, 0, sizeof(pool));
    free(pool);
}