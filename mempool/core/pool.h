#include <stdint.h>
#include <pthread.h>

#define POOL_BLOCKS_INITIAL 1

typedef struct poolFreed {
  struct poolFreed *nextFree;
} poolFreed;

typedef struct {
  uint32_t element_size;  // size of each element
  uint32_t block_size;    // size of each block
  uint32_t used;          // used element of current block
  int32_t block;          // current block can be use
  poolFreed *freed;       // blocks has been used
  uint32_t blocks_used;   // used block of total blocks
  uint8_t **blocks;       // array of block (pointer)
  pthread_mutex_t mutex;
} pool;


void pool_initialize(pool *n, uint32_t element_size, uint32_t block_size);
void pool_free_pool(pool *p);

void *pool_malloc(pool *p);
void pool_free(pool *p, void *ptr);

void pool_free_all(pool *p);
