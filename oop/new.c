#include "new.h"
#include "assert.h"

static int heap[MANY];

void *new(const void* type, ...)
{
  int *p;  // 

  for (p = heap + 1; p < heap + MANY; ++p) {
	if (! *p) {
	  break;
	}
  }
  assert(p < heap + MANY);
  *p = MANY;
  return p;
}

void delte(void *_item)
{
  int *item = _item;

  if (item)
  {
	assert(item > heap && item < heap + MANY);
	*item = 0;
  }
}
