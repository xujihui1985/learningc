#include "class.h"
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

void *new (const void *_class, ...)
{
  const struct Class *class = _class;
  void *p = calloc(1, class->size);

  assert(p);


  // p -> object (calloc(1, class->size)) -> class
  // p points to the beginning of the new memory area of the obejct
  // force a conversion of p which treats the beginning of the object
  // as a pointer to a `struct Class`, and set the argument class as 
  // the value of this pointer
  /**
struct String {
  const void * class;
  char *text; };
  how to understand?
  class is the first field of `struct String`, so p is a pointer to
  the object that created by calloc on heap, and because, the first
  field of object is class, so the (const struct Class **)p is point
  to class field of p.

   */
  * (const struct Class **) p = class;

  if (class->ctor)
  {
	va_list ap;
	va_start(ap, _class);
	p = class->ctor(p, &ap);
	va_end(ap);
  }
  return p;
}

void delete(void *self)
{
  const struct Class ** cp = self;
  if (self && (*cp) && (*cp)->dtor)
  {
	self = (*cp)->dtor(self);
  }
  free(self);
}

size_t sizeOf(const void *self)
{
  const struct Class * const * cp = self;
  assert(self && (*cp));
  return (*cp)->size;
}

