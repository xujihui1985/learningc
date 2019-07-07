#include "set.h"
#include "new.h"
#include <assert.h>


void 
*add(void *_set, const void *_element)
{
  int *set = _set;

  const int *element = _element;

  if (*element == MANY) {
	*(int *) element = set - heap;
  } else {
	assert(*element == set - heap);
  }

}
