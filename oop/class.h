#ifndef CLASS_H
#define CLASS_H

#include <stdlib.h>

struct Class {
  size_t size;

  void * (* ctor) (void *self, va_list *app);
  void * (* dtor) (void *self);
  void * (* clone) (const void *self);
};

#endif // CLASS_H

